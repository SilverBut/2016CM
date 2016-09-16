#include "common.h"
#include <cstring>

unsigned int hex2bytes(const char* hex, unsigned int blen, unsigned char* bytes){
	uint8_t pos,idx0,idx1;
	bzero(bytes, blen);
	for ( pos = 0 ; ((pos < (blen*2)) && (pos < strlen(hex))) ; pos+=2 ){
		idx0 = (uint8_t)hex[pos+0];
		idx1 = (uint8_t)hex[pos+1];
		bytes[pos/2] = (uint8_t) (hashmap[idx0]<<4) | hashmap[idx1];
	};
	return(0);
}
	
