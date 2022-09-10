#!/bin/sh
nvcc -c matrix_mul.cu -I/usr/local/cuda/NVIDIA_GPU_Computing_SDK/C/common/inc/ -L/usr/local/cuda/lib64/
g++ -o matrix matrix_mul.o main.c -I./ -I/usr/local/cuda/NVIDIA_GPU_Computing_SDK/C/common/inc/ -L/usr/local/cuda/lib64/ -lcuda -lcudart
