#pragma once
#include <cassert>
#include <cstdint>
#define DEBUG

//typedef unsigned short int uint8_t;
//typedef unsigned int uint32_t;
typedef unsigned int uint;

uint hex2bytes(const char* hex, uint blen, uint8_t* bytes);
uint bytes2hex(const uint8_t* bytes, uint blen, char* hex);
