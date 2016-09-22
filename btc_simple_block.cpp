#include "btc_simple_block.h"


Block_simple::Block_simple(){
    memset( &this->block_info, 0, sizeof(this->block_info) );
    //this->sha256_ctx = SHA256();
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
    return retv == 1;
}

bool Block_simple::loadblock(const uint8_t* buf){
    return buf == memcpy((uint8_t*)&this->block_info, buf, Block_simple::BLOCK_INFO_LENGTH);
}

size_t Block_simple::get_prevhash(uint8_t dst[Block_simple::HASH_LENGTH]){
    memcpy(dst, (uint8_t*)this->block_info.hashPrevBlock, Block_simple::HASH_LENGTH);
    return Block_simple::HASH_LENGTH;
}

bool Block_simple::mining(const uint8_t target[Block_simple::HASH_LENGTH]){
    uint32_t old_value = this->block_info.Nonce.in_int;
    uint8_t current[Block_simple::HASH_LENGTH];
    do{
        this->gethash(current);
        if (!memcmp(current,
                     target, 
                     Block_simple::HASH_LENGTH))
        {
            return true;
        }
        this->block_info.Nonce.in_int++;
    }while ( this->block_info.Nonce.in_int != old_value );//got an overflow
    return false;
}

BitChain::BitChain(){
    blist.clear();
  //  this->sha384_ctx = SHA384();
    this->sha384_ctx.init();
}


size_t BitChain::gethash(uint8_t dest[BitChain::HASH_LENGTH]){
    list<Block_simple>::iterator it_chain;
    size_t count = 0;

    uint8_t *block_hash = (uint8_t*)malloc(Block_simple::HASH_LENGTH);
    sha384_ctx.init();
    for ( it_chain = this->blist.begin();
          it_chain !=this->blist.end();
          it_chain++,count++  ){
        it_chain->gethash(block_hash);
        sha384_ctx.update(block_hash, Block_simple::HASH_LENGTH);
    }
    free(block_hash);
    sha384_ctx.final(dest); 

    return count;
}

bool BitChain::mining(const uint8_t last_hash[Block_simple::HASH_LENGTH]){

    list<Block_simple>::iterator it_chain;
    it_chain = this->blist.begin();
    uint8_t *target_hash = (uint8_t*)malloc(Block_simple::HASH_LENGTH);
    int i = 1 ;

    do{
        if ( i == this->blist.size() ){
            if ( last_hash )
            {
                memcpy(target_hash, last_hash, Block_simple::HASH_LENGTH);
            }
            else
            {
                throw new std::string("What the fuck HASH(HASH(X)) result you told me!");
            }
        } else {
            list<Block_simple>::iterator it_next = it_chain;
            it_next++;
            it_next->get_prevhash(target_hash);
        }
        //Calculate corrent Nonce
        if ( !it_chain->mining(target_hash) ) {
            return false;
        }
        it_chain++;
    } while ( i++ != this->blist.size()  );

    return true;
}

uint32_t BitChain::loadblock(FILE* fp){
    Block_simple current_block;
    uint32_t i = 0;
    while ( current_block.loadblock(fp) ){
        blist.push_back(current_block);        
        i++;
    }
    return i;
}