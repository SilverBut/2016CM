#pragma once

#include "common.h"
#include <list>

#define BLOCK_HASH_SIZE 32

typedef struct {
	uint8_t Version[4];
	uint8_t hashPrevBlock[32];
	uint8_t hashMerkleRoot[32];
	uint8_t Time[4];
	uint8_t Bits[4];
	uint8_t Nonce[4];
} blockchain_node;



class Chain{

	public:
		Chain ( const uint8_t* binary_chain );
		void hash( uint8_t* hash_storage );
		const size_t block_hash_size=BLOCK_HASH_SIZE;
	private:
		list<blockchain_node> chain;

};

bool verify_integrity( Chain* old_chain, Chain* new_chain );
