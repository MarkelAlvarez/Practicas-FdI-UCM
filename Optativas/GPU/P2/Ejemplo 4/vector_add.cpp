#include <CL/sycl.hpp>

using namespace cl::sycl;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "./exec N"<< std::endl;
		return(-1);
	}

	int N = atoi(argv[1]);

	sycl::queue Q(sycl::default_selector{});

	std::cout << "Running on "
		<< Q.get_device().get_info<sycl::info::device::name>()
		<< std::endl;

	int *a = malloc_shared<int>(N, Q); //TODO: create vectors with USM
	int *b = malloc_shared<int>(N, Q); //TODO: create vectors with USM
	int *c = malloc_shared<int>(N, Q); //TODO: create vectors with USM

	// Parallel for
	for(int i=0; i<N; i++)
	{
		a[i] = i;   // Init a
		b[i] = i*i; // Init b
	}	

	// Create a kernel to perform c=a+b
	Q.submit([&](handler &h) { 
		// Submit the kernel
		h.parallel_for(N, [=](id<1> i) {
			c[i] = a[i] + b[i];
		}); // End of the kernel function
	}).wait();

	for(int i = 0; i < N; i++)
	{
		std::cout << "c[" << i << "] = " << c[i] << std::endl;
	}

	free(a, Q);
	free(b, Q);
	free(c, Q);

	return 0;
}