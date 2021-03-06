#pragma once

#ifndef JUSTVM_UTIL_H
#define JUSTVM_UTIL_H

#include <string>
#include <fstream>
#include <vector>
#include <cassert>
#include <memory>
#include <cstdint>
#include <cstdlib>

#define BC_U1 uint8_t // Byte code u1
#define BC_U2 uint16_t // Byte code u2
#define BC_U4 uint32_t // Byte code u4

#define BC_U1_SIZE sizeof(BC_U1)
#define BC_U2_SIZE sizeof(BC_U2)
#define BC_U4_SIZE sizeof(BC_U4)

#define BYTE unsigned char
#define BYTE_SET std::vector<byte>

// define byte
typedef unsigned char byte;

// define some const string
const std::string SEPARATOR("/");
const std::string LIB_DIR("lib");
const std::string EXT_DIR("ext");
const std::string ALL_DIR("*");

// make pour point clear
template<typename PointName>
using Point = PointName *;

// int type
using uint8 = uint8_t;
using uint32 = uint32_t;
using uint16 = uint16_t;
using uint64 = uint64_t;

// read file msg
size_t getFileSize(FILE *file);

size_t getFileSize(const char *filePath);

Point<byte> readByteFromFile(Point<byte> byteChars, const char *filePath);

Point<byte> readByteFromFile(Point<byte> byteChars,
                             const size_t size = 0, const char *filePath = "");

void decode_mutf_8(Point<byte> byte_point, int len);

#endif //JUSTVM_UTIL_H
