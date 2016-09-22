#pragma once

#include "common.h"
#include "twofish.h"

#define FLAG_ENCRYPT_COUNT 10000000

const static size_t flag_key_len = 32;
const static size_t flag_iv_len  = 16;
const static size_t flag_len = 64;
//Key: 32bytes
//IV:  16bytes
//Flag:64bytes
void FlagEncrypt(const uint8_t key[flag_key_len], const uint8_t iv[flag_iv_len], const uint8_t flag[flag_len], uint8_t* encrypted);
void FlagDecrypt(const uint8_t key[flag_key_len], const uint8_t iv[flag_iv_len], const uint8_t cipher[flag_len], uint8_t* decrypted);
