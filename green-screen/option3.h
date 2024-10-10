#ifndef OPTION3_H
#define OPTION3_H

#include <stddef.h>

typedef struct rgb rgb;
typedef uint32_t pixel;
typedef struct PixelBuffer PixelBuffer;

struct PixelBuffer {
    pixel *pixels;
    int width;
    int height;
};

void blit(PixelBuffer *src, PixelBuffer* dest, size_t offsetX, size_t offsetY);

#endif
