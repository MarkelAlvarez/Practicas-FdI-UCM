#ifndef KERNEL_H 
#define KERNEL_H 

#include <CL/sycl.hpp>

using  namespace  cl::sycl;

void remove_noise_SYCL(sycl::queue Q, float *im, float *image_out, float thredshold, int window_size, int height, int width);
#endif
