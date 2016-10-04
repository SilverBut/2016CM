#pragma once
#include <cassert>
#include <cstring>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <xmmintrin.h>	//128 op
#include <immintrin.h>  //256 op
#ifdef IS_PROBLEM
#include "flag.h"
#endif
#include "flag_coder.h"

#define CLASS_CONSTANT const static

using std::cout;
using std::endl;

typedef unsigned int uint;

uint hex2bytes(const char* hex, uint blen, uint8_t* bytes);
uint bytes2hex(const uint8_t* bytes, uint blen, char* hex);
uint bytes2hexstring(const uint8_t* bytes, uint blen, char* hex);

void xor_16byte ( uint8_t* dst, uint8_t* src);
void xor_32byte ( uint8_t* dst, uint8_t* src);
void long_xor( uint8_t* dst, uint8_t* src, size_t length);

void hex_swaporder(char* bytes, size_t length);
void bin_swaporder(uint8_t* bytes, size_t length);