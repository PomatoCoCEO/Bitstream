//
// Created by Paulo Cortesão on 19/11/2020.
//

#ifndef BITSTREAM_BITSTREAM_H
#define BITSTREAM_BITSTREAM_H

#endif //BITSTREAM_BITSTREAM_H
#include <stdlib.h> // malloc, free
#include<stdio.h>

typedef struct {
    unsigned int *content;
    int posIn, posBlock, blockSize;
} Bitstream;

Bitstream *bitstream(int sizeBlock);
void add(Bitstream *a, int comp, int val);
void print(Bitstream *a);
int equal(Bitstream* a, Bitstream* b);
