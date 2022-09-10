#define NUM_BLOCKS 8
#define THREADS_PER_BLOCK 64

__global__ void example(int **data) {
    int value1, value2, value3, value4, value5;
    int idx1, idx2, idx3;

    idx1 = blockIdx.x * blockDim.x;
    idx2 = threadIdx.x;
    idx3 = idx1 + idx2;
    value1 = *(data[idx1]);
    value2 = *(data[idx2]);
    value3 = value1 + value2;
    value4 = value1 * value2;
    value5 = value3 + value4;
    *(data[idx3]) = value5;
    *(data[idx1]) = value3;
    *(data[idx2]) = value4;
    idx1 = idx2 = idx3 = 0;
}

int main(int argc, char *argv[]) {
    int *host_data[NUM_BLOCKS*THREADS_PER_BLOCK];
    int **dev_data;
    const int zero = 0;

    /* Allocate an integer for each thread in each block */
    for (int block = 0; block < NUM_BLOCKS; block++) {
        for (int thread = 0; thread < THREADS_PER_BLOCK; thread++) {
            int idx = thread + block * THREADS_PER_BLOCK;
            cudaMalloc(&host_data[idx], sizeof(int));
            cudaMemcpy(host_data[idx], &zero, sizeof(int), cudaMemcpyHostToDevice);
        }
    }

    /* This inserts an error into block 3, thread 33*/
    host_data[3*THREADS_PER_BLOCK + 33] = NULL;

    /* Copy the array of pointers to the device */
    cudaMalloc((void**)&dev_data, sizeof(host_data));
    cudaMemcpy(dev_data, host_data, sizeof(host_data), cudaMemcpyHostToDevice);

    /* Execute example */
    example <<< NUM_BLOCKS, THREADS_PER_BLOCK >>> (dev_data);
    cudaThreadSynchronize();
}

