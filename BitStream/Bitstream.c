//
// Created by Paulo Cortesão on 19/11/2020.
//

#include "Bitstream.h"

Bitstream *bitstream(int sizeBlock){
    if(sizeBlock<=0) sizeBlock = 1;
    Bitstream *ans = (Bitstream *)malloc(sizeof(Bitstream));
    ans->content = (unsigned int*)malloc(sizeof(unsigned int) * sizeBlock);
    ans->posBlock = ans->posIn = 0;
    ans->blockSize = sizeBlock;
    for (int i = 0; i < sizeBlock; i++) {
        ans->content[i] = 0;
    }
    return ans;
}

void add(Bitstream *a, int comp, int val) {
    if(val>=1<<comp) val &= ((1<<comp)-1); // precaution
    if (comp + a->posIn < sizeof(unsigned int)*8) {
        int freeBits = sizeof(unsigned int)*8 - a->posIn;
        unsigned int g = val << (freeBits - comp);
        a->content[a->posBlock] |= g;
        a->posIn += comp;
    } else {
        int freeBits = sizeof(unsigned int)*8 - a->posIn;
        unsigned int g = val >> (comp - freeBits);
        a->content[a->posBlock] |= g;
        a->posIn = 0;
        a->posBlock++;

        if(a->posBlock==a->blockSize) {
            unsigned int* d = (unsigned int*) malloc(sizeof(unsigned int)*a->blockSize*2);
            for(int i = 0; i<a->blockSize; i++) d[i]=a->content[i];
            for(int i = a->blockSize; i<2*a->blockSize; i++) d[i] = 0;
            unsigned int *toFree = a->content;
            a->content = d;
            free(toFree);
            a->blockSize*=2;
        }
        add(a, comp - freeBits, val & ((1 << (comp - freeBits))-1));
    }
}

void print(Bitstream *a) {
    for (int i = 0; i <= a->posBlock; i++) {
        for (int j = 0; j < (i == a->posBlock ? a->posIn : sizeof(int)*8 ); j++) {
            printf("%d", (((a->content[i])<<j)>>(sizeof(int)*8-1)));
        }
    }
    printf("\n");
}

int equal(Bitstream* a, Bitstream* b) {
    if(a->posBlock!=b->posBlock) return 0;
    if(a->posIn!=b->posIn) return 0;
    for(int i = 0; i<=a->posBlock; i++) {
        if(a->content[i]!=b->content[i]) return 0;
    }
    return 1;
}
