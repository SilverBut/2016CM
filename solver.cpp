#include <iostream>
#include <cstring>
//#include "lucky_boy.hpp"
#include "twofish.h"
#include "common.h"

#define MAX_TRIES 100000

void LongXor( uint8_t* src, uint8_t* dst );

int main(int argc, char* argv[]){
	int i = MAX_TRIES ;
	//LuckyChain* chain = new LuckyChain;		//load a lucky chain, and try to solve for 200 blocks
	//
	//LuckyHash oldhash = LuckyChain -> getHash();	//Get old hash of the last block
	//chain->LoadMoreBlock("moreblock.bin", 500);					//Try to calculate 500 new blocks
	//
	//LuckyHash newhash = LuckyChain -> getHash();	//Get new hash of the last block
	//const char *keyHex = newhash;
	const char *skeyHex = "BADC0DE01234ABCD6789ABCD1234DEFFAABB2233BBAA22339988DDCC4455DDCC";
	Twofish crypt;
	TwofishKey key;
	uint8_t skey[32];
	int j = hex2bytes(skeyHex, strlen(skeyHex), skey);
	crypt.PrepareKey(skey, 32, &key);

		
	// use a simple CFB method to encrypt our flag string
	uint8_t cipherResult[4][16];
	// prepare flag
	const char *flag = "xdctf{N3v3r_buy_btc_un1es_u_want_2_learn_crypt0_lol_padding_now}";
	uint8_t flagArray[4][16];
	assert(strlen(flag)==64);
	memcpy(flagArray, flag, 64);
	// prepare IV
	const char *ivHex  = "DEADBEEF0BADC0DE8086012450301120";	//our iv
	uint8_t iv[16];
	assert(strlen(ivHex)==32);
	hex2bytes(ivHex, strlen(ivHex), iv);
	// encryption is for 100 rounds
	for ( int loop = 0 ; loop < 100000000 ; loop++ ){
		uint8_t midKey[16];
		crypt.Encrypt(&key, iv, midKey);
		LongXor(midKey, flagArray[0]);
		memcpy(cipherResult[0], midKey, 16);
		for ( int round = 1 ; round < 4 ; round++ ){
			crypt.Encrypt(&key, cipherResult[round-1], midKey);
			LongXor(midKey, flagArray[round]);
			memcpy(cipherResult[round], midKey, 16);
		}
		memcpy(flagArray, cipherResult, 64);
		if (!strcmp((char*)cipherResult, flag)){
			printf("%s\n", flagArray);
		}
	}


	return 0;
}

void LongXor( uint8_t* src, uint8_t* dst ){
	for ( int i = 0 ; i < 16 ; i++ ){
		src[i] ^= dst[i];
	}
}

