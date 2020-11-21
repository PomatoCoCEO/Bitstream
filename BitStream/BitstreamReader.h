//
// Created by Paulo Cortesão on 19/11/2020.
//

#ifndef BITSTREAM_BITSTREAMREADER_H
#define BITSTREAM_BITSTREAMREADER_H

#endif //BITSTREAM_BITSTREAMREADER_H

#include "Bitstream.h"
#define reveal(a,d) printf(#a" = %"#d"\n",a);

typedef struct {
    Bitstream* bitstream;
    int posInRead, posBlockRead;
} BitstreamReader;

BitstreamReader * bitstreamReader(Bitstream* bitstream);

unsigned int read(BitstreamReader* bitstreamReader, int comp);