//
// Created by Paulo Cortesão on 19/11/2020.
//

#include "BitstreamReader.h"

BitstreamReader * bitstreamReader(Bitstream* bitstream) {
    BitstreamReader* ans = malloc(sizeof(BitstreamReader));
    ans->bitstream = bitstream;
    ans->posInRead = 0;
    ans->posBlockRead = 0;
    return ans;
}

unsigned int read(BitstreamReader* bitstreamReader, int comp) {
    unsigned int ans = 0;
    if(bitstreamReader->posInRead+comp<8*sizeof(unsigned int)) {
        unsigned int aid = bitstreamReader->bitstream->content[bitstreamReader->posBlockRead];
        ans = aid >> (8*sizeof(unsigned int)-bitstreamReader->posInRead-comp) & ((1<<comp)-1);
        bitstreamReader->posInRead+=comp;
        return ans;
    }
    else{
        unsigned int aid = bitstreamReader->bitstream->content[bitstreamReader->posBlockRead];
        unsigned int readForNow = (8*sizeof(unsigned int)-bitstreamReader->posInRead); // no of bits to read now
        unsigned int and = (1<<readForNow)-1;
        if(readForNow==8*sizeof(unsigned int)) and = -1;
        ans += and&aid;
        ans <<= (comp-readForNow);
        bitstreamReader->posBlockRead++;
        if(bitstreamReader->posBlockRead==bitstreamReader->bitstream->blockSize) return -1;
        bitstreamReader->posInRead = 0;
        return ans + read(bitstreamReader, comp-readForNow);
    }
}