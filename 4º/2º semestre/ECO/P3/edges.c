#include <stdio.h>
#include <stdlib.h>
#include <float.h>

/* Constant declaration */
#define MAX_IMAGESIZE  4096
#define MAX_BRIGHTNESS  255 /* Maximum gray level */
#define GRAYLEVEL       256 /* No. of gray levels */
#define MAX_FILENAME    256 /* Filename length limit */
#define MAX_BUFFERSIZE  256

/* Global variables */
unsigned char image1[MAX_IMAGESIZE][MAX_IMAGESIZE];
unsigned char image2[MAX_IMAGESIZE][MAX_IMAGESIZE];


void load_image_file(char *filename, unsigned char image[MAX_IMAGESIZE][MAX_IMAGESIZE], int *x_size, int *y_size)
{
  char buffer[MAX_BUFFERSIZE];
  FILE *fp; /* File pointer */
  int max_gray; /* Maximum gray level */
  int x, y; /* Loop variable */
  
  /* Input file open */
  fp = fopen(filename, "rb");
  if (NULL == fp) {
    printf("     The file doesn't exist!\n\n");
    exit(1);
  }
  /* Check of file-type ---P5 */
  fgets(buffer, MAX_BUFFERSIZE, fp);
  if (buffer[0] != 'P' || buffer[1] != '5') {
    printf("     Mistaken file format, not P5!\n\n");
    exit(1);
  }
  /* input of x_size, y_size */
  *x_size = 0;
  *y_size = 0;
  while (*x_size == 0 || *y_size == 0) {
    fgets(buffer, MAX_BUFFERSIZE, fp);
    if (buffer[0] != '#') {
      sscanf(buffer, "%d %d", x_size, y_size);
    }
  }
  /* input of max_gray */
  max_gray = 0;
  while (max_gray == 0) {
    fgets(buffer, MAX_BUFFERSIZE, fp);
    if (buffer[0] != '#') {
      sscanf(buffer, "%d", &max_gray);
    }
  }
  if (*x_size > MAX_IMAGESIZE || *y_size > MAX_IMAGESIZE) {
    printf("     Image size exceeds %d x %d\n\n", 
           MAX_IMAGESIZE, MAX_IMAGESIZE);
    printf("     Please use smaller images!\n\n");
    exit(1);
  }
  if (max_gray != MAX_BRIGHTNESS) {
    printf("     Invalid value of maximum gray level!\n\n");
    exit(1);
  }
  /* Input of image data*/
  for (y = 0; y < *y_size; y++) {
    for (x = 0; x < *x_size; x++) {
      image[y][x] = (unsigned char)fgetc(fp);
    }
  }
  fclose(fp);
}


void save_image_file(char *filename, unsigned char image[MAX_IMAGESIZE][MAX_IMAGESIZE], int x_size, int y_size)
/* into pgm file with header & body information */
{
  FILE *fp; /* File pointer */
  int x, y; /* Loop variable */
  
  fp = fopen(filename, "wb");
  /* output of pgm file header information */
  fputs("P5\n", fp);
  fputs("# Created by Image Processing\n", fp);
  fprintf(fp, "%d %d\n", x_size, y_size);
  fprintf(fp, "%d\n", MAX_BRIGHTNESS);
  /* Output of image data */
  for (y = 0; y < y_size; y++) {
    for (x = 0; x < x_size; x++) {
      fputc(image[y][x], fp);
    }
  }
  fclose(fp);
}


void gaussian(unsigned char image1[MAX_IMAGESIZE][MAX_IMAGESIZE],
  unsigned char image2[MAX_IMAGESIZE][MAX_IMAGESIZE], int x_size, int y_size )
     /* Spatial filtering of image data */
     /* Gaussian filter */
     /* Input: image1[y][x] ---- Outout: image2[y][x] */
{
  int weight[5][5] = {{ 1,  4,  6,  4,  1 },
                      { 4, 16, 24, 16,  4 },
                      { 6, 24, 36, 24,  6 },
                      { 4, 16, 24, 16,  4 },
                      { 1,  4,  6,  4,  1 }};
  double pixel_value;
  double min, max;
  int x, y, i, j;  /* Loop variable */

  /* Initialization of image2[y][x] */
  for (y = 0; y < y_size; y++) {
    image2[y][0] = 0;
    image2[y][x_size] = 0;
  }
  for (x = 0; x < x_size; x++) {
    image2[0][x] = 0;
    image2[y_size][x] = 0;
  }

  /* Generation of image2 after linear transformtion */
  for (y = 2; y < y_size - 2; y++) {
    for (x = 2; x < x_size - 2; x++) {
      pixel_value = 0.0;
      for (j = - 1; j < 4; j++) {
            for (i = -1; i < 4; i++) {
              pixel_value += (double) weight[j + 1][i + 1] * image1[y + j][x + i]/256.0;
            }
      }
      image2[y][x] = (unsigned char)pixel_value;
    }
  }
}


void laplacian(unsigned char image1[MAX_IMAGESIZE][MAX_IMAGESIZE],
  unsigned char image2[MAX_IMAGESIZE][MAX_IMAGESIZE], int x_size, int y_size )
     /* Spatial filtering of image data */
     /* Laplacian filter */
     /* Input: image1[y][x] ---- Outout: image2[y][x] */
{
  int weight[5][5] = {{ 1,  1, 1, 1, 1 },
		      { 1, 1,  1, 1, 1 },
		      { 1, 1,-24, 1, 1 },
		      { 1, 1,  1, 1, 1 },
		      { 1, 1,  1, 1, 1 }};

  double pixel_value;
  int x, y, i, j;  /* Loop variable */
  
  /* Initialization of image2[y][x] */
  for (y = 0; y < y_size; y++) {
    image2[y][0] = 0;
    image2[y][x_size] = 0;
  }
  for (x = 0; x < x_size; x++) {
    image2[0][x] = 0;
    image2[y_size][x] = 0;
  }
  
  /* Generation of image2 after linear transformtion */
  for (y = 2; y < y_size - 2; y++) {
    for (x = 2; x < x_size - 2; x++) {
      pixel_value = 0.0;
      for (j = - 1; j < 4; j++) {
	    for (i = -1; i < 4; i++) {
	      pixel_value += (double) weight[j + 1][i + 1] * image1[y + j][x + i];
	    }
      }
      if (pixel_value > 255) pixel_value=255;
      if (pixel_value < 0) pixel_value=0;
      image2[y][x] = (unsigned char)pixel_value;
    }
  }
}

void edges(unsigned char image1[MAX_IMAGESIZE][MAX_IMAGESIZE],
  unsigned char image2[MAX_IMAGESIZE][MAX_IMAGESIZE], int x_size, int y_size )
     /* Edge detection */
     /* Input: image1[y][x] ---- Outout: image2[y][x] */
{
  gaussian(image1, image2, x_size, y_size);
  gaussian(image2, image1, x_size, y_size);
  laplacian(image1, image2, x_size, y_size);
}

int main(int argc, char *argv[])
{
  int x_size, y_size;

  if (argc != 3) {
    printf("     USAGE: %s in.pgm out.pgm\n\n", argv[0]);
    exit(1);
  }

  load_image_file(argv[1], image1, &x_size, &y_size);

  edges(image1, image2, x_size, y_size);

  save_image_file(argv[2], image2, x_size, y_size);

  return 0;
}
