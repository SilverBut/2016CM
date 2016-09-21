#pragma once

#include "twofish.h"

#define FLAG_ENCRYPT_COUNT 1000000

//Key: 32bytes
//IV:  16bytes
//Flag:64bytes
void FlagEncrypt(const uint8_t* key, const uint8_t* iv, const uint8_t* flag, uint8_t* encrypted);
void FlagDecrypt(const uint8_t* key, const uint8_t* iv, const uint8_t* cipher, uint8_t* decrypted);
