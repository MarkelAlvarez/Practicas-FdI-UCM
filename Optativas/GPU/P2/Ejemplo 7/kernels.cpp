#include <CL/sycl.hpp>
#include <math.h>

using namespace cl::sycl;

#define MAX_WINDOW_SIZE 5*5

void buble_sort_SYCL(float array[], int size)
{
	int i, j;
	float tmp;

	for (i=1; i<size; i++)
	{
		for (j=0 ; j<size - i; j++)
		{
			if (array[j] > array[j+1])
			{
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
		}	
	}
}

void remove_noise_SYCL(sycl::queue Q, float *im, float *image_out, float thredshold, int window_size, int height, int width)
{
	buffer<float,1> buf_im{im, range<1>{(size_t)width*height}};

	Q.submit([&](handler &h)
	{
		accessor acc_im{buf_im, h, read_write};
		const int B = 16;
		range num_groups = range<2>(width, height);
		range group_size = range<2>(B, B);

		h.parallel_for_work_group(num_groups, group_size, [=](group<2> grp)
		{
			int i = grp.get_id(0);
			int j = grp.get_id(1);
			
			float window[MAX_WINDOW_SIZE];
			float median;
			int ws2 = (window_size-1)>>1;
			
			grp.parallel_for_work_item([&](h_item<2> it)
			{	
				int ii = i * B + it.get_local_id(0);
				int jj = j * B + it.get_local_id(1);

				if (i < height - ws2)
				{
					if (j < width - ws2)
					{
						for (ii =- ws2; ii <= ws2; ii++)
						{
							for (jj =- ws2; jj <= ws2; jj++)
							{
								window[(ii+ws2)*window_size + jj+ws2] = acc_im[(i+ii)*width + j+jj];
							}
						}

						buble_sort_SYCL(window, window_size*window_size);
						median = window[(window_size*window_size-1)>>1];

						if (fabsf((median-im[i*width+j])/median) <=thredshold)
						{
							image_out[i*width + j] = im[i*width+j];
						}
						else
						{
							image_out[i*width + j] = median;
						}
					}
				}
			});
		});
	});

	Q.wait();
}