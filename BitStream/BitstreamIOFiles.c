//
// Created by Paulo Cortesão on 20/11/2020.
//

#include "BitstreamIOFiles.h"

void writeBitstreamToFile(Bitstream* a, char* nameOfFile) { // writing the bitstream and its contens on a file
    FILE* ptr = fopen(nameOfFile,"w");
    fwrite(a, sizeof(Bitstream),1,ptr);
    fwrite(a->content, sizeof(int), a->blockSize, ptr); // for optimization we could
    fclose(ptr);
}

void readBitstreamFromFile(Bitstream* a, char* nameOfFile) {
    FILE* ptr = fopen(nameOfFile,"r");
    fread(a,sizeof(Bitstream), 1, ptr);
    a->content = malloc(a->blockSize*sizeof(unsigned int)); // allocationg storage for content
    fread(a->content, sizeof(int), a->blockSize, ptr);
    fclose(ptr);
}