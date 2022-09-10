############################
#  Makefile for cross-compile #
############################
all : kernels main

CUDA_INCLUDE=/usr/local/cuda/include/
CUDA_LIB=/usr/local/cuda-7.5/lib64/
LIB=-lcudart -lcublas
CC=gcc
NVCC=nvcc 
LINK=g++
CFLAGS  = -O3  
NVCCFLAGS = $(CFLAGS)

# For a standard c++ code, we use CC
main : main.c 
	$(CC)   -c main.c $(CFLAGS) -I. -I$(CUDA_INCLUDE) -L$(CUDA_LIB) $(LIB)
	$(LINK) -o matrix matrix_mul.o main.o $(CFLAGS) -I. -I$(CUDA_INCLUDE) -L$(CUDA_LIB) $(LIB)

# For a standard CUDA code, we just invoke nvcc
kernels: matrix_mul.cu
	$(NVCC) -c matrix_mul.cu $(NVCCFLAGS) -I. -I$(CUDA_INCLUDE) $(LIB)

clean : 
	rm -f *.o matrix