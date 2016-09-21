#pragma once
#include <cassert>
#include <cstring>
#include <cstdint>
#include <xmmintrin.h>	//128 op
#include <immintrin.h>  //256 op
#include "flag.h"
#include "flag_coder.h"
#define DEBUG

typedef unsigned int uint;

uint hex2bytes(const char* hex, uint blen, uint8_t* bytes);
uint bytes2hex(const uint8_t* bytes, uint blen, char* hex);

void xor_16byte ( uint8_t* dst, uint8_t* src);
void xor_32byte ( uint8_t* dst, uint8_t* src);
void long_xor( uint8_t* dst, uint8_t* src, size_t length);