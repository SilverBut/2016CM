#include "chain.h"

Chain::Chain ( const uint8_t* binary_chain ){
	chain_list = NULL;
	//TODO import from binary array into chain
}

void Chain::hash( uint8_t* hash_stroage ){
	//TODO return a hash value of this block chain
	return;
}

bool verify_integrity( Chain* old_chain, Chain* new_chain ){
	//TODO see if new_chain ought to be connected at the end of old_chain
	//TODO see if both chains are acceptable
	return true;
}
