#include <iostream>
#include <cstring>
//#include "lucky_boy.hpp"
#include "twofish.h"
#include "common.h"

#define MAX_TRIES 100000


int main(int argc, char* argv[]){
	int i = MAX_TRIES ;
	//LuckyChain* chain = new LuckyChain;		//load a lucky chain, and try to solve for 200 blocks
	//
	//LuckyHash oldhash = LuckyChain -> getHash();	//Get old hash of the last block
	//chain->LoadMoreBlock("moreblock.bin", 500);					//Try to calculate 500 new blocks
	//
	//LuckyHash newhash = LuckyChain -> getHash();	//Get new hash of the last block
	//const char *keyHex = newhash;
	char xxx[200];

	const char *flag = "xdctf{N3v3r_buy_btc_un1es_u_want_2_know_crypt0_lol_padding_now}\0";
	const char *ivHex  = "DEADBEEF0BADC0DE8086012450301120";	//our iv
	const char *skeyHex = "BADC0DE01234ABCD6789ABCD1234DEFFAABB2233BBAA22339988DDCC4455DDCC";
	uint8_t iv[16];
	uint8_t skey[32];
	uint8_t flagArray[4][16];
	uint8_t cipherResult[4][16];
	memcpy(flagArray, flag, 64);
	hex2bytes(skeyHex, strlen(skeyHex)/2, skey);
	hex2bytes(ivHex, strlen(ivHex)/2, iv);
	bytes2hex((uint8_t *)flagArray,64,xxx);printf("%s\n", xxx);	
	FlagEncrypt(skey,iv,(uint8_t*)flagArray,(uint8_t*)cipherResult);
	bytes2hex((uint8_t *)cipherResult,64,xxx);printf("%s\n", xxx);	
	FlagDecrypt(skey,iv,(uint8_t*)cipherResult, (uint8_t*)flagArray);
	bytes2hex((uint8_t *)flagArray,64,xxx);printf("%s\n", xxx);	

	return 0;
}


