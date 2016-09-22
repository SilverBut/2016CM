#include "btc_simple_block.h"


Block_simple::Block_simple(){
    memset( &this->block_info, 0, sizeof(this->block_info) );
    this->sha256_ctx = SHA256();
    this->sha256_ctx.init();
    return;
}

size_t Block_simple::gethash(uint8_t dest[Block_simple::HASH_LENGTH]){
    uint8_t middle[Block_simple::HASH_LENGTH];
    sha256_ctx.init();
    sha256_ctx.update((uint8_t*)&this->block_info, Block_simple::BLOCK_INFO_LENGTH);
    sha256_ctx.final(middle);
    sha256_ctx.init();
    sha256_ctx.update(middle, Block_simple::HASH_LENGTH);
    sha256_ctx.final(dest);
    return 0;
}

bool Block_simple::loadblock(FILE* fp){
    uint8_t* temp = (uint8_t*)malloc(Block_simple::BLOCK_INFO_LENGTH);
    size_t retv  = fread(temp, Block_simple::BLOCK_INFO_LENGTH, 1, fp);
    this->loadblock(temp);
    return retv == Block_simple::BLOCK_INFO_LENGTH;
}

bool Block_simple::loadblock(const uint8_t* buf){
    return buf == memcpy((uint8_t*)&this->block_info, buf, Block_simple::BLOCK_INFO_LENGTH);
}