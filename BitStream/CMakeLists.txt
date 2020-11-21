cmake_minimum_required(VERSION 3.17)
project(BitStream C)

set(CMAKE_C_STANDARD 11)

add_executable(BitStream main.c Bitstream.c Bitstream.h BitstreamReader.c BitstreamReader.h BitstreamIOFiles.c BitstreamIOFiles.h)