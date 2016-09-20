#include "flag_coder.h"

void FlagDecrypt(const uint8_t* key, const uint8_t* iv, const uint8_t* cipher, uint8_t* decrypted){
	Twofish crypt;
	TwofishKey twKey;

	uint8_t cipherResult[4][16];
	uint8_t flagArray[4][16];
	uint8_t midKey[16];
	memcpy(flagArray, cipher, 64);
	crypt.PrepareKey(key, 32, &twKey);
	for ( int loop = 0 ; loop < 1000000 ; loop++ ){
		memcpy(midKey, iv, 16);
		for ( int round = 0 ; round < 4 ; round++ ){
			crypt.Decrypt(&twKey, cipherResult[round], flagArray[round]);
			xor_16byte(flagArray[round], midKey);
			memcpy(midKey, cipherResult[round],16);
		}
		memcpy(cipherResult, flagArray, 64);
	}
	memcpy(decrypted, cipherResult, 64);
}

void FlagEncrypt(const uint8_t* key, const uint8_t* iv, const uint8_t* flag, uint8_t* encrypted){
	Twofish crypt;
	TwofishKey twKey;

	uint8_t cipherResult[4][16];
	uint8_t flagArray[4][16];
	uint8_t midKey[16];
	memcpy(flagArray, flag, 64);
	crypt.PrepareKey(key, 32, &twKey);
	for ( int loop = 0 ; loop < 1000000 ; loop++ ){
		memcpy(midKey, iv, 16);
		for ( int round = 0 ; round < 4 ; round++ ){
			xor_16byte(midKey, flagArray[round]);
			crypt.Encrypt(&twKey, midKey, cipherResult[round]);
			memcpy(midKey, cipherResult[round], 16);
		}
		memcpy(flagArray, cipherResult, 64);
	}
	memcpy(encrypted, cipherResult, 64);
}

