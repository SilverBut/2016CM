#pragma once

#include "common.h"

#define BLOCK_HASH_SIZE 32

typedef struct {
	uint32_t version;
	uint32_t prev_block[8];//32 byte
	uint32_t merkle_root[8];//32 byte
	uint32_t timestamp;
	uint32_t bits;
	uint32_t nonce;
	uint8_t  number_of_trans;
	uint32_t version_2;
	uint8_t  input;
	uint32_t prev_output[9];
	uint8_t script_length;
	

} blockchain_node;

class Chain{

	public:
		Chain ( const uint8_t* binary_chain );
		void hash( uint8_t* hash_storage );
		const size_t block_hash_size=BLOCK_HASH_SIZE;
	private:
		blockchain_node* chain_list;

};

bool verify_integrity( Chain* old_chain, Chain* new_chain );
