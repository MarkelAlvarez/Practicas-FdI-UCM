#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cuda.h>

#include "routinesGPU.h"
#define BLOCK_SIZE 16
#define DEG2RAD 0.017453f

void getlines(int threshold, uint32_t *accumulators, int accu_width, int accu_height, int width, int height, float *sin_table, float *cos_table, int *x1_lines, int *y1_lines, int *x2_lines, int *y2_lines, int *lines)
{
	int rho, theta, ii, jj;
	uint32_t max;

	for(rho = 0; rho < accu_height; rho++)
	{
		for(theta = 0; theta < accu_width; theta++)  
		{  
			if(accumulators[(rho*accu_width) + theta] >= threshold)  
			{  
				//Is this point a local maxima (9x9)  
				max = accumulators[(rho*accu_width) + theta]; 
				for(int ii = -4; ii <= 4; ii++)  
				{  
					for(int jj = -4; jj <= 4; jj++)  
					{  
						if( (ii + rho >= 0 && ii + rho < accu_height) && (jj + theta >= 0 && jj + theta < accu_width))  
						{  
							if(accumulators[((rho + ii) * accu_width) + (theta + jj)] > max)  
							{
								max = accumulators[((rho + ii) * accu_width) + (theta + jj)];
							}  
						}  
					}  
				}  

				if(max == accumulators[(rho * accu_width) + theta]) //local maxima
				{
					int x1, y1, x2, y2;  
					x1 = y1 = x2 = y2 = 0;  

					if(theta >= 45 && theta <= 135)  
					{
						if (theta>90)
						{
							//y = (r - x cos(t)) / sin(t)  
							x1 = width/2;  
							y1 = ((float)(rho-(accu_height/2)) - ((x1 - (width/2) ) * cos_table[theta])) / sin_table[theta] + (height / 2);
							x2 = width;  
							y2 = ((float)(rho-(accu_height/2)) - ((x2 - (width/2) ) * cos_table[theta])) / sin_table[theta] + (height / 2);  
						}
						else
						{
							//y = (r - x cos(t)) / sin(t)  
							x1 = 0;  
							y1 = ((float)(rho-(accu_height/2)) - ((x1 - (width/2) ) * cos_table[theta])) / sin_table[theta] + (height / 2);
							x2 = width*2/5;  
							y2 = ((float)(rho-(accu_height/2)) - ((x2 - (width/2) ) * cos_table[theta])) / sin_table[theta] + (height / 2); 
						}
					}
					else
					{
						//x = (r - y sin(t)) / cos(t);  
						y1 = 0;  
						x1 = ((float)(rho-(accu_height/2)) - ((y1 - (height/2) ) * sin_table[theta])) / cos_table[theta] + (width / 2);  
						y2 = height;  
						x2 = ((float)(rho-(accu_height/2)) - ((y2 - (height/2) ) * sin_table[theta])) / cos_table[theta] + (width / 2);  
					}
					
					x1_lines[*lines] = x1;
					y1_lines[*lines] = y1;
					x2_lines[*lines] = x2;
					y2_lines[*lines] = y2;
					(*lines)++;
				}
			}
		}
	}
}

void init_cos_sin_table(float *sin_table, float *cos_table, int n)
{
	int i;

	for (i=0; i<n; i++)
	{
		sin_table[i] = sinf(i*DEG2RAD);
		cos_table[i] = cosf(i*DEG2RAD);
	}
}

__global__ void calculateNR(uint8_t *im, float *NR, int height, int width)
{
	int i = blockIdx.y*blockDim.y + threadIdx.y+2;
	int j = blockIdx.x*blockDim.x + threadIdx.x+2;
	int col = threadIdx.x+2;
	int row = threadIdx.y+2;	
	__shared__ uint8_t imgCompartida[BLOCK_SIZE + 4][BLOCK_SIZE + 4];
	
	imgCompartida[threadIdx.y + 2][threadIdx.x + 2] = im[(i)*width+(j)];
	
	if(!threadIdx.x)
	{
		imgCompartida[threadIdx.y+2][threadIdx.x+1] = im[(i)*width+(j-1)];
		imgCompartida[threadIdx.y+2][threadIdx.x] = im[(i)*width+(j-2)];
	}
	if(!threadIdx.y)
	{
		imgCompartida[threadIdx.y+1][threadIdx.x+2] = im[(i-1)*width+(j)];
		imgCompartida[threadIdx.y][threadIdx.x+2] = im[(i-2)*width+(j)];
	}
	if(threadIdx.x == BLOCK_SIZE-1)
	{
		imgCompartida[threadIdx.y+2][threadIdx.x+3] = im[(i)*width+(j+1)];
		imgCompartida[threadIdx.y+2][threadIdx.x+4] = im[(i)*width+(j+2)];
	}
	if(threadIdx.y == BLOCK_SIZE-1)
	{
		imgCompartida[threadIdx.y+3][threadIdx.x+2] = im[(i+1)*width+(j)];
		imgCompartida[threadIdx.y+4][threadIdx.x+2] = im[(i+2)*width+(j)];
	}
	
	if(((i >= 2) && (i < height - 2)) && ((j >= 2) && (j < width-2)))
	{
		NR[i*width+j] =
				 (2.0*imgCompartida[row-2][col-2] 	+  4.0*imgCompartida[row-2][col-1] 	+  5.0*imgCompartida[row-2][col] 	+  4.0*imgCompartida[row-2][col+1] 	+ 2.0*imgCompartida[row-2][col+2]
				+ 4.0*imgCompartida[row-1][col-2] 	+  9.0*imgCompartida[row-1][col-1] 	+ 12.0*imgCompartida[row-1][col] 	+  9.0*imgCompartida[row-1][col+1] 	+ 4.0*imgCompartida[row-1][col+2]
				+ 5.0*imgCompartida[row][col-2] 	+ 12.0*imgCompartida[row][col-1] 	+ 15.0*imgCompartida[row][col] 		+ 12.0*imgCompartida[row][col+1] 	+ 5.0*imgCompartida[row][col-2]
				+ 4.0*imgCompartida[row+1][col-2] 	+  9.0*imgCompartida[row+1][col-1] 	+ 12.0*imgCompartida[row+1][col] 	+  9.0*imgCompartida[row+1][col+1] 	+ 4.0*imgCompartida[row+1][col+2]
				+ 2.0*imgCompartida[row+2][col-2] 	+  4.0*imgCompartida[row+2][col-1] 	+  5.0*imgCompartida[row+2][col] 	+  4.0*imgCompartida[row+2][col+1]	+ 2.0*imgCompartida[row+2][col+2])
				/159.0;

	}
}

__global__ void calculateGPhi(float *NR, float *G, float *phi, float *Gx, float *Gy, int height, int width)
{
	int i, j;
	float PI = 3.141593;
		
	i = blockIdx.y * blockDim.y + threadIdx.y;
	j = blockIdx.x * blockDim.x + threadIdx.x;

	phi[i*width+j] = 0;

	if(((i >=2) && (i < height-2)) && ((j >=2) && (j < width-2))) {
		// Intensity gradient of the image
		Gx[i*width+j] = 
					(1.0*NR[(i-2)*width+(j-2)] 	+  2.0*NR[(i-2)*width+(j-1)] +  (-2.0)*NR[(i-2)*width+(j+1)] + (-1.0)*NR[(i-2)*width+(j+2)]
					+ 4.0*NR[(i-1)*width+(j-2)] +  8.0*NR[(i-1)*width+(j-1)] +  (-8.0)*NR[(i-1)*width+(j+1)] + (-4.0)*NR[(i-1)*width+(j+2)]
					+ 6.0*NR[(i  )*width+(j-2)] + 12.0*NR[(i  )*width+(j-1)] + (-12.0)*NR[(i  )*width+(j+1)] + (-6.0)*NR[(i  )*width+(j+2)]
					+ 4.0*NR[(i+1)*width+(j-2)] +  8.0*NR[(i+1)*width+(j-1)] +  (-8.0)*NR[(i+1)*width+(j+1)] + (-4.0)*NR[(i+1)*width+(j+2)]
					+ 1.0*NR[(i+2)*width+(j-2)] +  2.0*NR[(i+2)*width+(j-1)] +  (-2.0)*NR[(i+2)*width+(j+1)] + (-1.0)*NR[(i+2)*width+(j+2)]);


		Gy[i*width+j] = 
					((-1.0)*NR[(i-2)*width+(j-2)] 	+ (-4.0)*NR[(i-2)*width+(j-1)]	+ (-6.0)*NR[(i-2)*width+(j)] 	+ (-4.0)*NR[(i-2)*width+(j+1)]	+ (-1.0)*NR[(i-2)*width+(j+2)]
					+ (-2.0)*NR[(i-1)*width+(j-2)] 	+ (-8.0)*NR[(i-1)*width+(j-1)]	+ (-12.0)*NR[(i-1)*width+(j)] 	+ (-8.0)*NR[(i-1)*width+(j+1)] 	+ (-2.0)*NR[(i-1)*width+(j+2)]
					+ 2.0*NR[(i+1)*width+(j-2)] 	+ 8.0*NR[(i+1)*width+(j-1)] 	+ 12.0*NR[(i+1)*width+(j)] 		+ 8.0*NR[(i+1)*width+(j+1)] 	+ 2.0*NR[(i+1)*width+(j+2)]
					+ 1.0*NR[(i+2)*width+(j-2)] 	+ 4.0*NR[(i+2)*width+(j-1)] 	+ 6.0*NR[(i+2)*width+(j)] 		+ 4.0*NR[(i+2)*width+(j+1)] 	+ 1.0*NR[(i+2)*width+(j+2)]);

		G[i*width+j]   = sqrtf((Gx[i*width+j]*Gx[i*width+j])+(Gy[i*width+j]*Gy[i*width+j]));	//G = √Gx²+Gy²
		phi[i*width+j] = atan2f(fabs(Gy[i*width+j]), fabs(Gx[i*width+j]));

		if(fabs(phi[i*width+j])<=PI/8)
		{
			phi[i*width+j] = 0;
		}
			
		else if (fabs(phi[i*width+j])<= 3*(PI/8))
		{
			phi[i*width+j] = 45;
		}
			
		else if (fabs(phi[i*width+j]) <= 5*(PI/8))
		{
			phi[i*width+j] = 90;
		}
			
		else if (fabs(phi[i*width+j]) <= 7*(PI/8))
		{
			phi[i*width+j] = 135;
		}
		else
		{
			phi[i*width+j] = 0;
		}	
	}
}

__global__ void calculatePedge(float *G, float *phi, /*uint8_t*/ int *pedge, int height, int width)
{
	int i, j;

	i = blockIdx.y * blockDim.y + threadIdx.y;
	j = blockIdx.x * blockDim.x + threadIdx.x;
	
	pedge[i*width+j] = 0;

	if(((i >=3) && (i < height-3)) && ((j >=3) && (j < width-3)))
	{
		if(phi[i*width+j] == 0)
		{
			if(G[i*width+j]>G[i*width+j+1] && G[i*width+j]>G[i*width+j-1]) //edge is in N-S
			{
				pedge[i*width+j] = 1;
			}

		}
		else if(phi[i*width+j] == 45)
		{
			if(G[i*width+j]>G[(i+1)*width+j+1] && G[i*width+j]>G[(i-1)*width+j-1]) // edge is in NW-SE
			{
				pedge[i*width+j] = 1;
			}

		}
		else if(phi[i*width+j] == 90)
		{
			if(G[i*width+j]>G[(i+1)*width+j] && G[i*width+j]>G[(i-1)*width+j]) //edge is in E-W
			{
				pedge[i*width+j] = 1;
			}

		}
		else if(phi[i*width+j] == 135)
		{
			if(G[i*width+j]>G[(i+1)*width+j-1] && G[i*width+j]>G[(i-1)*width+j+1]) // edge is in NE-SW
			{
				pedge[i*width+j] = 1;
			}
		}
	}
}

__global__ void calculateImageOut(uint8_t *image_out, float *G, int *pedge, float level, int height, int width)
{
	int i, j;
	int ii, jj;
	float lowthres = level/2;
	float hithres = 2*(level);
	
	i = blockIdx.y * blockDim.y + threadIdx.y;
	j = blockIdx.x * blockDim.x + threadIdx.x;

	// Hysteresis Thresholding
	image_out[i*width+j] = 0;

	if(((i >=3) && (i < height-3)) && ((j >=3) && (j < width-3)))
	{
		if(G[i*width+j]>hithres && pedge[i*width+j])
		{
			image_out[i*width+j] = 255;
		}
		else if(pedge[i*width+j] && G[i*width+j]>=lowthres && G[i*width+j]<hithres)
		{
			// check neighbours 3x3
			for (ii=-1;ii<=1; ii++)
			{
				for (jj=-1;jj<=1; jj++)
				{
					if (G[(i+ii)*width+j+jj]>hithres)
					{
						image_out[i*width+j] = 255;
					}
				}
			}
		}
	}
}

void cannyGPU(uint8_t *im, uint8_t *image_out, float*NR, float *G, float *phi, float *Gx, float *Gy, /*uint8_t*/ int *pedge, float level, int height, int width)
{
	dim3 threads(BLOCK_SIZE, BLOCK_SIZE);
	
	int hBlocks = height/BLOCK_SIZE;
	if(height % BLOCK_SIZE != 0)
	{
		hBlocks++;
	}

	int wBlocks = width / BLOCK_SIZE;
	if (width % BLOCK_SIZE!= 0)
	{
		wBlocks + 1;
	}

	dim3 blocks(hBlocks, wBlocks);
	
	calculateNR<<<blocks, threads>>>(im, NR, height, width);
	cudaDeviceSynchronize();

	calculateGPhi<<<blocks,threads>>>(NR, G, phi, Gx, Gy, height, width);
	cudaDeviceSynchronize();
	
	calculatePedge<<<blocks,threads>>>(G, phi, pedge, height, width);
	cudaDeviceSynchronize();
	
	calculateImageOut<<<blocks,threads>>>(image_out, G, pedge, level, height, width);
}

void houghtransform(uint8_t *im, int width, int height, uint32_t *accumulators, int accu_width, int accu_height, float *sin_table, float *cos_table)
{
	int i, j, theta;

	float hough_h = ((sqrt(2.0) * (float)(height>width?height:width)) / 2.0);

	for(i=0; i<accu_width*accu_height; i++)
		accumulators[i]=0;	

	float center_x = width/2.0; 
	float center_y = height/2.0;

	for(i=0;i<height;i++)  
	{  
		for(j=0;j<width;j++)  
		{  
			if( im[ (i*width) + j] > 250 ) // Pixel is edge  
			{  
				for(theta=0;theta<180;theta++)  
				{  
					float rho = ( ((float)j - center_x) * cos_table[theta]) + (((float)i - center_y) * sin_table[theta]);
					accumulators[ (int)((round(rho + hough_h) * 180.0)) + theta]++;

				} 
			} 
		} 
	}
}

void line_asist_GPU(uint8_t *im, int height, int width, uint8_t *imEdge, float *NR, float *G, float *phi, float *Gx, float *Gy, uint8_t *pedge, float *sin_table, float *cos_table, uint32_t *accum, int accu_height, int accu_width, int *x1, int *x2, int *y1, int *y2, int *nlines)
{
	int threshold, size = height * width;
	
	uint8_t* matrix;
	cudaMalloc((uint8_t**)&matrix, size * sizeof(uint8_t));
	cudaMemcpy(matrix, im, size * sizeof(uint8_t), cudaMemcpyHostToDevice);

	//reservamos memoria para la salida de canny y las demas matrices
	uint8_t* matrixOut;
	cudaMalloc((uint8_t**)&matrixOut, size  * sizeof(uint8_t));

	float* noiseReduction_GPU;
	cudaMalloc((float**)&noiseReduction_GPU, size  * sizeof(float));
	
	float* G_GPU;
	cudaMalloc((float**)&G_GPU, size * sizeof(float));

	float* phi_GPU;
	cudaMalloc((float**)&phi_GPU, size * sizeof(float));

	float* gx_GPU;
	cudaMalloc((float**)&gx_GPU, size * sizeof(float));

	float* gy_GPU;
	cudaMalloc((float**)&gy_GPU, size * sizeof(float));

	//uint8_t* pedge_GPU; 
	//cudaMalloc((float**)&pedge_GPU, size * sizeof(uint8_t));
	int *pedge_GPU; 
	cudaMalloc((float**)&pedge_GPU, size * sizeof(int));

	uint8_t* accum_GPU;
	cudaMalloc(&accum_GPU, accu_width * accu_height * sizeof(uint32_t));

	cannyGPU(matrix, matrixOut, noiseReduction_GPU, G_GPU, phi_GPU, gx_GPU, gy_GPU, pedge_GPU, 1000.0f, height, width);

	/* hough transform */
	houghtransform(imEdge, width, height, accum, accu_width, accu_height, sin_table, cos_table);
	cudaMemcpy(accum, accum_GPU, accu_width * accu_height * sizeof(uint32_t), cudaMemcpyDeviceToHost);
	
	if (width > height)
	{
		threshold = width/6;
	}
	else
	{
		threshold = height/6;
	}

	cudaMemcpy(matrix, matrixOut, size * sizeof(float),cudaMemcpyDeviceToHost);

	getlines(threshold, accum, accu_width, accu_height, width, height, sin_table, cos_table, x1, y1, x2, y2, nlines);
}