#include <stdlib.h>
#include <stdio.h>
#include "option3.h"

// Copies the entire image from `src` into a destination buffer `dest`.
// The pixel buffers have a top-left origin and are row-major.
// `offsetX` and `offsetY` denote the origin within `dest` where `src` should be copied.
// Any pixel that exactly matches `COLOR_KEY` should be skipped.
// You may assume input buffers are pre-allocated and sufficiently large to complete the requested operation.
unsigned int COLOR_KEY = 0x01FF1300;

void blit(PixelBuffer *src, PixelBuffer* dest, size_t offsetX, size_t offsetY) {
    for (int y = 0; y < src->height; y++) {
        for (int x = 0; x < src->width; x++) {
            pixel src_pixel = src->pixels[y * src->width + x];
            
            if (src_pixel == COLOR_KEY) {
                continue;
            }

            size_t destX = offsetX + x;
            size_t destY = offsetY + y;

            if (destX < dest->width && destY < dest->height) {
                dest->pixels[destY * dest->width + destX] = src_pixel;
            }
        }
    }

}