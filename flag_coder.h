#pragma once

#include "twofish.h"

#define FLAG_ENCRYPT_COUNT 1000000

void FlagEncrypt(const uint8_t* key, const uint8_t* iv, const uint8_t* flag, uint8_t* encrypted);
void FlagDecrypt(const uint8_t* key, const uint8_t* iv, const uint8_t* cipher, uint8_t* decrypted);
