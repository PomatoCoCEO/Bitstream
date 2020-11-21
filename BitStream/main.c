#include <stdio.h>
#include<stdlib.h>

//#include "BitstreamReader.h" // already includes bitstream
#include "BitstreamIOFiles.h"
//unidade de teste para a bitstream

int main() {
    Bitstream* a = bitstream(0);
    //BitstreamReader* b = bitstreamReader(a);
    for(int i = 0; i<32; i++) {
        add(a,5,30);
    }
    print(a);
    unsigned int h;
    //h = read(b,sizeof(int)*8); // already working with 32-bit numbers
    char* nameOfFile = "bitstream.bin";
    writeBitstreamToFile(a,nameOfFile);
    Bitstream* c = bitstream(0);
    readBitstreamFromFile(c,nameOfFile);
    print(c);
    printf("%d", equal(a,c));
    return 0;
}
