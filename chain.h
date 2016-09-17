#pragma once

#include "common.h"

typedef struct {
	
} blockchain_node;

class Chain{

	public:
		Chain ( const uint8_t* binary_chain );
		void hash( uint8_t* hash_storage );
	private:
		blockchain_node* chain_list;

};

bool verify_integrity( Chain* old_chain, Chain* new_chain );
