#include <CL/sycl.hpp>

using namespace cl::sycl;

void matrix_mult_C(float *a, float *b, float *c, int N)
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			c[i*N+j] = 0.0f;
			for(int k=0; k<N; k++)
			{
				c[i*N+j] += a[i*N+k]*b[k*N+j];
			}
		}
	}
}

void matrix_mult_naive(sycl::queue Q, float *a, float *b, float *c, int N)
{
	// Create a command_group to issue command to the group
	Q.submit([&](handler &h) {
		// Submit the kernel
		h.parallel_for(range<2>(N, N), [=](id<2> item)
		{
			auto i = item[0];
			auto j = item[1];
			// CODE THAT RUNS ON DEVICE
			c[i*N+j] = 0.0f;
			for(int k=0; k<N; k++)
			{
				c[i*N+j] += a[i*N+k]*b[k*N+j];
			}
		}); // End of the kernel function
	}).wait();  // End of the queue commands we waint on the event reported.
}

void matrix_mult_hierarchy(sycl::queue Q, float *a, float *b, float *c, int N)
{
	const int B = 16;

	// Create a command_group to issue command to the group
	Q.submit([&](handler &h) {
		range num_groups = range<2>(N/B, N/B); // N is a multiple of B
		range group_size = range<2>(B, B);

		h.parallel_for_work_group(num_groups, group_size, [=](group<2> grp)
		{
			int ib = grp.get_id(0);
			int jb = grp.get_id(1);

			grp.parallel_for_work_item([&](h_item<2> it) {
				// kernel function is executed once per work-item
				int i = ib * B + it.get_local_id(0);
				int j = jb * B + it.get_local_id(1);
			
				for(int k=0; k<N; k++)
				{
					c[i*N+j] += a[i*N+k]*b[k*N+j];
				}
			});
		});
	}).wait();  // End of the queue commands we waint on the event reported.
}

void matrix_mult_local(sycl::queue Q, float *a, float *b, float *c, int N)
{
	// Local accessor, for one matrix tile:
	constexpr int tile_size = 16;

	// Create a command_group to issue command to the group
	Q.submit([&](handler &h) {
		// Traditional accessors, representing matrices in global memory:
		/*accessor matrixA{a, h};
		accessor matrixB{b, h};
		accessor matrixC{c, h};*/

		// Local accessor, for one matrix tile:
		constexpr int tile_size = 16;
		accessor<float, 2, sycl::access::mode::read_write, sycl::access::target::local> tileA(range<2>(tile_size, tile_size), h);
		accessor<float, 2, sycl::access::mode::read_write, sycl::access::target::local> tileB(range<2>(tile_size, tile_size), h);

		// Submit the kernel
		h.parallel_for(nd_range<2>(range<2>(N, N), range<2>(tile_size, tile_size)), [=](nd_item<2> item)
		{
			auto n = item.get_global_id()[0];
			auto m = item.get_global_id()[1];

			// Index in the local index space:
			auto j = item.get_local_id()[0];
			auto i = item.get_local_id()[1];
			float sum = 0;

			for (int kk = 0; kk < N; kk += tile_size)
			{
				// Load the matrix A, matrix B and synchronize
				// to ensure all work-items have a consistent view
				// of the matrix tile in local memory.
				tileA[i][j] = a[m*j+kk];
				tileB[i][j] = b[i+kk*n];
				item.barrier();

				// Perform computation using the local memory tile
				for (int k = 0; k < tile_size; k++)
				{
					sum += a[i*N+k]*b[k*N+j];
				}
				// After computation, synchronize again, to ensure all
				// reads from the local memory tile are complete.
				item.barrier();
			}

			// Write the final result to global memory.
			c[m+n] = sum;
		}); // End of the kernel function
	}).wait();  // End of the queue commands we waint on the event reported.
}

int check_results(float *c, float *c_test, int N)
{
	for(int i=0; i<N; i++)
	{		
		for(int j=0; j<N; j++)
		{
			if (abs((c_test[i*N+j]-c[i*N+j]))/c[i*N+j]>1e-4)
			{
				printf("  ERROR in [%i, %i]: %f %f\n", i, j, c_test[i*N+j], c[i*N+j]);
				return(0);
			}
		}
	}

	return(1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "./exec N"<< std::endl;

		return(-1);
	}

	int N = atoi(argv[1]);

	sycl::queue Q(sycl::gpu_selector{});

	std::cout << "Running on " << Q.get_device().get_info<sycl::info::device::name>() << std::endl;

	// a in USM
	float *a = malloc_shared<float>(N*N, Q);
	float *b = malloc_shared<float>(N*N, Q);
	float *c = malloc_shared<float>(N*N, Q);
	float *c_test = malloc_host<float>(N*N, Q);

	// Parallel for
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			a[i*N+j] = i+j;   // Init a
			b[i*N+j] = i*i+1; // Init b
		}
	}

	// Matrix Multiplication test
	matrix_mult_C(a, b, c_test, N);

	matrix_mult_naive(Q, a, b, c, N);
	if (check_results(c, c_test, N))
	{
		printf("TEST NAIVE_MULT PASSED\n");
	}
	else
	{
		printf("TEST NAIVE_MULT FAILED\n");
	}

	matrix_mult_hierarchy(Q, a, b, c, N);
	if (check_results(c, c_test, N))
	{
		printf("TEST HIERARCHY_MULT PASSED\n");
	}
	else
	{
		printf("TEST HIERARCHY_MULT FAILED\n");
	}

	matrix_mult_local(Q, a, b, c, N);
	if (check_results(c, c_test, N))
	{
		printf("TEST LOCAL_MULT PASSED\n");
	}
	else
	{
		printf("TEST LOCAL_MULT FAILED\n");
	}

	free(a, Q);
	free(b, Q);
	free(c, Q);
	free(c_test, Q);

	return 0;
}