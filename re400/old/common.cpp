#include "common.h"

void long_xor( uint8_t* dst, uint8_t* src, size_t length){
	for ( size_t i = 0 ; i*16 < length ; i++ ){
		xor_16byte( &dst[i*16], &src[i*16] );
	}
}

void xor_16byte ( uint8_t* dst, uint8_t* src){
	__m128 x;
	__m128 y;
	x = _mm_load_ps((float*)dst);
	y = _mm_load_ps((float*)src);
	x = _mm_xor_ps(x,y);
	_mm_storeu_ps((float*)dst, x);
}

void xor_32byte ( uint8_t* dst, uint8_t* src){
	__m256 x;
	__m256 y;
	x = _mm256_load_ps((float*)dst);
	y = _mm256_load_ps((float*)src);
	x = _mm256_xor_ps(x,y);
	_mm256_storeu_ps((float*)dst, x);
}

uint bytes2hex(const uint8_t* bytes, uint blen, char* hex){
	for(uint i = 0 ; i < blen ; i++){
		hex[i*2] = (uint8_t)(bytes[i]>>4)>9?(bytes[i]>>4)+'A'-0xA:(bytes[i]>>4)+'0';
		hex[i*2+1] = (uint8_t)(bytes[i]&0xf)>9?(bytes[i]&0xf)+'A'-0xA:(bytes[i]&0xf)+'0';
	}
	return blen*2;
}

uint hex2bytes(const char* hex, uint blen, uint8_t* bytes){
	uint8_t pos,idx0,idx1;
	const uint8_t hashmap[] =
	{
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ........
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //  !"#$%&'
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ()*+,-./
     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, // 01234567
     0x08, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 89:;<=>?
     0x00, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x00, // @ABCDEFG
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // HIJKLMNO
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // PQRSTUVW
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // XYZ[\]^_
     0x00, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x00, // `abcdefg
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // hijklmno
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // pqrstuvw
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // xyz{|}~.
	};
	bzero(bytes, blen);
	for ( pos = 0 ; ((pos < (blen*2)) && (pos < strlen(hex))) ; pos+=2 ){
		idx0 = (uint8_t)hex[pos+0];
		idx1 = (uint8_t)hex[pos+1];
		bytes[pos/2] = (uint8_t) (hashmap[idx0]<<4) | hashmap[idx1];
	};
	return(0);
}
	
