#ifndef PNG_IO_H
#define PNG_IO_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" 
#endif
uint8_t*read_png_fileRGB(const char *filename, int *width, int *height);

#ifdef __cplusplus
extern "C" 
#endif
void write_png_fileRGB(const char *filename, uint8_t *image_uchar, int width, int height);

#ifdef __cplusplus
extern "C" 
#endif
uint8_t *read_png_fileBW(const char *filename, int *width, int *height);

#ifdef __cplusplus
extern "C" 
#endif
void write_png_fileBW(const char *filename, uint8_t *image_uchar, int width, int height);

#endif
