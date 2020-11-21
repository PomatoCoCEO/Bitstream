//
// Created by Paulo Cortesão on 20/11/2020.
//

#ifndef BITSTREAM_BITSTREAMIOFILES_H
#define BITSTREAM_BITSTREAMIOFILES_H

#endif //BITSTREAM_BITSTREAMIOFILES_H

#include<stdio.h>
#include<stdlib.h>
#include "Bitstream.h"

void writeBitstreamToFile(Bitstream* a, char* nameOfFile);

void readBitstreamFromFile(Bitstream* a, char* nameOfFile);