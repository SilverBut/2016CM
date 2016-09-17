#pragma once
#include <cassert>
#include "twofish.h"
#include <cstring>
#include <cstdint>
#define DEBUG

//typedef unsigned short int uint8_t;
//typedef unsigned int uint32_t;
typedef unsigned int uint;

uint hex2bytes(const char* hex, uint blen, uint8_t* bytes);
uint bytes2hex(const uint8_t* bytes, uint blen, char* hex);

void FlagEncrypt(const uint8_t* key, const uint8_t* iv, const uint8_t* flag, uint8_t* encrypted);
void FlagDecrypt(const uint8_t* key, const uint8_t* iv, const uint8_t* cipher, uint8_t* decrypted);

void LongXor( uint8_t* src, uint8_t* dst );
