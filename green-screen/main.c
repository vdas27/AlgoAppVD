#include <stdlib.h>
#include <stdio.h>
#include "option3.h"


PixelBuffer *read_image_p3(FILE *f) {
    char format[3];
    int max_color;
    PixelBuffer *img = (PixelBuffer *)malloc(sizeof(PixelBuffer));

    if (img == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    
    fscanf(f, "%2s", format);
    fscanf(f, "%u %u %d\n", &img->width, &img->height, &max_color);
    img->pixels = (pixel *)malloc(sizeof(pixel) * img->width * img->height);

    if (img->pixels == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(img);
        return NULL;
    }

    for (unsigned int i = 0; i < img->width * img->height; ++i) {
        unsigned int r, g, b;
        fscanf(f, "%u %u %u", &r, &g, &b);
        img->pixels[i] = (r * 0x01000000) + (g * 0x00010000) + (b * 0x00000100);
    }
    return img;
}

void write_image_p3(FILE* f, PixelBuffer *img) {
    fprintf(f, "P3\n");
    fprintf(f, "%i %i %u\n", img->width, img->height, 255);

    for (int i = 0; i < (img->width * img->height); i++) {
        pixel rgb = img->pixels[i];
        unsigned int r = (rgb & 0xFF000000) >> 24;
        unsigned int g = (rgb & 0x00FF0000)>> 16;
        unsigned int b = (rgb & 0x0000FF00) >> 8;
        fprintf(f,"%u %u %u\n", r, g, b);
    }
}

int main(int argc, char *argv[]) {
    PixelBuffer *src;
    
    if (argv[1]){
        FILE *f = fopen(argv[1], "r");
        src = read_image_p3(f);
    } else {
        printf("No src file inputted\n");
        return 1;
    }
    
    PixelBuffer *dest = (PixelBuffer *)malloc(sizeof(PixelBuffer));
    if (dest == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    dest->height = src->height;
    dest->width = src->width;
    dest->pixels = (pixel *)malloc(sizeof(pixel) * dest->width * dest->height);
    
    int offsetx = (argv[3]) ? atoi(argv[3]) : 0;
    int offsety = (argv[4]) ? atoi(argv[4]) : 0;

    blit(src, dest, offsetx, offsety);
    
    if (argv[2]) {
        FILE *g = fopen(argv[2], "w");
        write_image_p3(g, dest);
    } else {
        printf("No dest file inputted\n");
        return 1;
    }

    return 0;
}