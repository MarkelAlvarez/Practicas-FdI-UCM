#ifndef ROUTINES_H
#define ROUTINES_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" 
#endif
uint8_t *image_RGB2BW(uint8_t *image_in, int height, int width);


#ifdef __cplusplus
extern "C" 
#endif
void draw_lines(uint8_t *imgtmp, int width, int height, int *x1, int *y1, int *x2, int *y2, int nlines);

#ifdef __cplusplus
extern "C" 
#endif
void init_cos_sin_table(float *sin_table, float *cos_table, int n);

#ifdef __cplusplus
extern "C" 
#endif
void line_asist_CPU(uint8_t *im, int height, int width,
	uint8_t *imEdge, float *NR, float *G, float *phi, float *Gx, float *Gy, uint8_t *pedge,
	float *sin_table, float *cos_table, 
	uint32_t *accum, int accu_height, int accu_width,
	int *x1, int *y1, int *x2, int *y2, int *nlines);

#endif

