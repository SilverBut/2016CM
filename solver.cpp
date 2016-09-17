#include <iostream>
#include <fstream>
#include <cstring>
#include "twofish.h"
#include "common.h"
#include "chain.h"
#include "sha384.h"

#define LEN_CHAIN_HASH 32

int main(int argc, char* argv[]){

	std::cout << "Loading old blocks...";
	// Get block info from the program itself
	/*
	Chain( uint8_t* )
	Chain* old_chain = new Chain( load_res_from_program('chain_info') );
	/**/
	std::cout << "Succeed.\n";
	
	std::cout << "Loading standrad blocks...";
	// Get block info from external files
	/*
	ifstream standrad_block_file;
	size_t size = 0;
	standrad_block_file.open(pStandradBlockName, ios::in|ios::binary|ios::ate );
	if (inFile.is_open()){
		char* standrad_block;
		size = standrad_block_file.tellg();
		standrad_block_file.seekg(0, ios::beg);
		standrad_block = new char[size+1];
		standrad_block_file.read(standrad_block, size);
		standrad_block[size] = '\n';
	} else {
	  std::cout << "File NOT exists. Exiting.\n" << std::endl;
		return -1;
	}
	Chain* new_chain = new Chain( standrad_block );
	/**/
	std::cout << "Succeed.\n";

	// Verify if two chains are both acceptable, and connectable
	std::cout << "Verifying now...";
	/*
	if ( !verify_integrity( old_chain, new_chain ) )
	{
		std::cout << "Failed.\n";
		return -2;
	}
	/**/
	std::cout << "Succeed.\n";
	
	// Get hash of the new chain and old chain
	std::cout << "Getting hash of two chains...";
	
	uint8_t old_chain_hash[LEN_CHAIN_HASH];
	uint8_t new_chain_hash[LEN_CHAIN_HASH];
	/*
	old_chain.hash(old_chain_hash);
	new_chain.hash(new_chain_hash);
	/**/
	std::cout << "Succeed.\n";

	// Generate iv(first 16 bytes of sha384) and Key(other bytes);
	std::cout << "Calculating IV and KEYs...";
	long_xor(old_chain_hash, new_chain_hash, LEN_CHAIN_HASH);
	uint8_t key_hash[SHA384::DIGEST_SIZE];
	memset(key_hash,0,SHA384::DIGEST_SIZE);
	SHA384 sha384_ctx = SHA384();
	sha384_ctx.init();
	sha384_ctx.update( old_chain_hash, LEN_CHAIN_HASH );
	sha384_ctx.final(key_hash);
	uint8_t iv[16];
	uint8_t skey[32];
	memcpy(iv, key_hash, 16);
	memcpy(skey, &key_hash[16], 32);
	/**/
	std::cout << "Succeed.\n";

	char xxx[200];

	const char *flag = "xdctf{N3v3r_buy_btc_un1es_u_want_2_know_crypt0_lol_padding_now}\0";
	const char *ivHex  = "DEADBEEF0BADC0DE8086012450301120";	//our iv
	const char *skeyHex = "BADC0DE01234ABCD6789ABCD1234DEFFAABB2233BBAA22339988DDCC4455DDCC";
	//uint8_t iv[16];
	//uint8_t skey[32];
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


