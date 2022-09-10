/*
 * A simple libpng example program
 * http://zarb.org/~gc/html/libpng.html
 *
 * Modified by Yoshimasa Niwa to make it much simpler
 * and support all defined color_type.
 * Copyright 2002-2010 Guillaume Cottenceau.
 *
 * This software may be freely redistributed under the terms
 * of the X11 license.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <png.h>
#include "png_io.h"

uint8_t *read_png_fileRGB(const char *filename, int *width, int *height)
{
	png_byte color_type;
	png_byte bit_depth;
	png_bytep *row_pointers;

	FILE *fp = fopen(filename, "rb");

	png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if(!png) abort();

	png_infop info = png_create_info_struct(png);
	if(!info) abort();

	if(setjmp(png_jmpbuf(png))) abort();

	png_init_io(png, fp);

	png_read_info(png, info);

	*width      = png_get_image_width(png, info);
	*height     = png_get_image_height(png, info);
	color_type = png_get_color_type(png, info);
	bit_depth  = png_get_bit_depth(png, info);

	// Read any color_type into 8bit depth, RGBA format.
	// See http://www.libpng.org/pub/png/libpng-manual.txt

	if(bit_depth == 16)
		png_set_strip_16(png);

	if(color_type == PNG_COLOR_TYPE_PALETTE)
		png_set_palette_to_rgb(png);

	// PNG_COLOR_TYPE_GRAY_ALPHA is always 8 or 16bit depth.
	if(color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
		png_set_expand_gray_1_2_4_to_8(png);

	if(png_get_valid(png, info, PNG_INFO_tRNS))
		png_set_tRNS_to_alpha(png);

	// These color_type don't have an alpha channel then fill it with 0xff.
	if(color_type == PNG_COLOR_TYPE_RGB ||
		color_type == PNG_COLOR_TYPE_GRAY ||
		color_type == PNG_COLOR_TYPE_PALETTE)
		png_set_filler(png, 0xFF, PNG_FILLER_AFTER);

	if(color_type == PNG_COLOR_TYPE_GRAY ||
		color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
		png_set_gray_to_rgb(png);

	png_read_update_info(png, info);

	row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * *height);
	for(int i = 0; i < *height; i++) {
		row_pointers[i] = (png_byte*)malloc(png_get_rowbytes(png,info));
	}

	png_read_image(png, row_pointers);

	uint8_t *image_uchar = (uint8_t*)malloc(3*(*width) * (*height));

	for(int i = 0; i < *height; i++) 
		for(int j = 0; j < *width; j++){ 
			image_uchar[3*(i* *width+j)  ] = (uint8_t)(row_pointers[i][j*4+0]);
			image_uchar[3*(i* *width+j)+1] = (uint8_t)(row_pointers[i][j*4+1]);
			image_uchar[3*(i* *width+j)+2] = (uint8_t)(row_pointers[i][j*4+2]);
		}
	fclose(fp);

	return(image_uchar);
}

void write_png_fileRGB(const char *filename, uint8_t *image_uchar, int width, int height) {

	FILE *fp = fopen(filename, "wb");
	if(!fp) abort();

	png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png) abort();

	png_infop info = png_create_info_struct(png);
	if (!info) abort();

	if (setjmp(png_jmpbuf(png))) abort();

	png_init_io(png, fp);

	// Output is 8bit depth, RGBA format.
	png_set_IHDR(
		png,
		info,
		width, height,
		8,
		PNG_COLOR_TYPE_RGBA,
		PNG_INTERLACE_NONE,
		PNG_COMPRESSION_TYPE_DEFAULT,
		PNG_FILTER_TYPE_DEFAULT
	);
	png_write_info(png, info);

	// To remove the alpha channel for PNG_COLOR_TYPE_RGB format,
	// Use png_set_filler().
	//png_set_filler(png, 0, PNG_FILLER_AFTER);

	png_bytep *row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * height);
	for(int i = 0; i < height; i++)
	{
		row_pointers[i] = (png_byte*)malloc(png_get_rowbytes(png,info));
	}

	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			row_pointers[i][j*4+0] = image_uchar[3*(i*width+j)+0]; //Red
			row_pointers[i][j*4+1] = image_uchar[3*(i*width+j)+1]; //Green
			row_pointers[i][j*4+2] = image_uchar[3*(i*width+j)+2]; //Blue
			row_pointers[i][j*4+3] = 255; //Alpha: full opacity
		}
	}

	png_write_image(png, row_pointers);
	png_write_end(png, NULL);

	for(int y = 0; y < height; y++)
	{
		free(row_pointers[y]);
	}
	
	free(row_pointers);

	fclose(fp);
}

uint8_t *read_png_fileBW(const char *filename, int *width, int *height) {

	png_byte color_type;
	png_byte bit_depth;
	png_bytep *row_pointers;

	FILE *fp = fopen(filename, "rb");

	png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if(!png) abort();

	png_infop info = png_create_info_struct(png);
	if(!info) abort();

	if(setjmp(png_jmpbuf(png))) abort();

	png_init_io(png, fp);

	png_read_info(png, info);

	*width      = png_get_image_width(png, info);
	*height     = png_get_image_height(png, info);
	color_type = png_get_color_type(png, info);
	bit_depth  = png_get_bit_depth(png, info);

	// Read any color_type into 8bit depth, RGBA format.
	// See http://www.libpng.org/pub/png/libpng-manual.txt

	if(bit_depth == 16)
		png_set_strip_16(png);

	if(color_type == PNG_COLOR_TYPE_PALETTE)
		png_set_palette_to_rgb(png);

	// PNG_COLOR_TYPE_GRAY_ALPHA is always 8 or 16bit depth.
	if(color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
		png_set_expand_gray_1_2_4_to_8(png);

	if(png_get_valid(png, info, PNG_INFO_tRNS))
		png_set_tRNS_to_alpha(png);

	// These color_type don't have an alpha channel then fill it with 0xff.
	if(color_type == PNG_COLOR_TYPE_RGB ||
		color_type == PNG_COLOR_TYPE_GRAY ||
		color_type == PNG_COLOR_TYPE_PALETTE)
		png_set_filler(png, 0xFF, PNG_FILLER_AFTER);

	if(color_type == PNG_COLOR_TYPE_GRAY ||
		color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
		png_set_gray_to_rgb(png);

	png_read_update_info(png, info);

	row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * *height);
	for(int i = 0; i < *height; i++) {
		row_pointers[i] = (png_byte*)malloc(png_get_rowbytes(png,info));
	}

	png_read_image(png, row_pointers);

	uint8_t *image_uchar = (uint8_t*)malloc((*width) * (*height));

	for(int i = 0; i < *height; i++) 
		for(int j = 0; j < *width; j++){ 
			image_uchar[(i*(*width)+j)  ] = (uint8_t)(row_pointers[i][4*j]);
		}
	fclose(fp);

	return(image_uchar);
}

void write_png_fileBW(const char *filename, uint8_t *image_uchar, int width, int height) {

	FILE *fp = fopen(filename, "wb");
	if(!fp) abort();

	png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png) abort();

	png_infop info = png_create_info_struct(png);
	if (!info) abort();

	if (setjmp(png_jmpbuf(png))) abort();

	png_init_io(png, fp);

	// Output is 8bit depth, RGBA format.
	png_set_IHDR(
		png,
		info,
		width, height,
		8,
		PNG_COLOR_TYPE_GRAY,
		PNG_INTERLACE_NONE,
		PNG_COMPRESSION_TYPE_DEFAULT,
		PNG_FILTER_TYPE_DEFAULT
	);
	png_write_info(png, info);

	// To remove the alpha channel for PNG_COLOR_TYPE_RGB format,
	// Use png_set_filler().
	//png_set_filler(png, 0, PNG_FILLER_AFTER);

	png_bytep *row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * height);
	for(int i = 0; i < height; i++) {
		row_pointers[i] = (png_byte*)malloc(png_get_rowbytes(png,info));
	}
	for(int i = 0; i < height; i++) 
		for(int j = 0; j < width; j++){
			row_pointers[i][j] = image_uchar[i*width+j]; 
	}



	png_write_image(png, row_pointers);
	png_write_end(png, NULL);

	for(int y = 0; y < height; y++) {
		free(row_pointers[y]);
	}
	free(row_pointers);

	fclose(fp);
}


#if 0
int main(int argc, char *argv[]) {

	int w, h;
	uint8_t *im;
	if(argc != 4){
		printf("./exec image_in.png image_out.png b/c [b: black&white format, c: color format]\n");
		return(-1);
	}

	if (!strcmp(argv[3],"c"))
	{
		im = read_png_fileRGB(argv[1], &w, &h);
		write_png_fileRGB(argv[2], im, w, h);
	} else {
		im = read_png_fileBW(argv[1], &w, &h);
		write_png_fileBW(argv[2], im, w, h);
	}

	return 0;
}

#endif
