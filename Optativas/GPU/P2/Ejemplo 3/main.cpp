#include <CL/sycl.hpp>

using namespace cl::sycl;

int main(int argc, char **argv)
{
	if (argc!=2)
	{
		std::cout << "./exec N"<< std::endl;
		return(-1);
	}

	int N = atoi(argv[1]);

	sycl::queue Q(sycl::gpu_selector{});

	std::cout << "Running on "
		<< Q.get_device().get_info<sycl::info::device::name>()
		<< std::endl;

	// a in USM
	float *a = malloc_shared<float>(N, Q);

	// Parallel for
	for(int i=0; i<N; i++)
	{
		a[i] = i; // Init a
	}

	// Create a command_group to issue command to the group
	Q.submit([&](handler &h) {
		// Submit the kernel
		h.parallel_for(N, [=](id<1> i)
		{
			a[i]*=2.0f;
		}); // End of the kernel function
	}).wait();       // End of the queue commands we waint on the event reported.

	for(int i=0; i<N; i++)
	{
		std::cout << "a[" << i << "] = " << a[i] << std::endl;
	}

	return 0;
}