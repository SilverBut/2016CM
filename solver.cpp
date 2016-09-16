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
	const char *keyHex = "BADC0DE01234ABCD6789ABCD1234DEFFAABB2233BBAA22339988DDCC4455DDCC";
	Twofish crypt;
	TwofishKey key;
	unsigned char p[32];
	int j = hex2bytes(keyHex, strlen(keyHex), p);
	crypt.PrepareKey(p, 32, &key);

		
	//use a simple CFB method to encrypt our flag string
	const char *flag = "xdctf{N3v3r_buy_btc_un1es_u_want_2_learn_crypt0_lol_padding_now}";
	assert(strlen(flag)==64);
	//prepare IVs
	const char *ivHex  = "DEADBEEF0BADC0DE8086012450301120";	//our iv
	//encryption is for 100 rounds
		

	return 0;
}

