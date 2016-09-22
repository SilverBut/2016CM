#pragma once
#include "common.h"
#include "sha256.h"
#include "sha384.h"
#include <list>

using std::list;

class Block_simple {
    public:
        CLASS_CONSTANT size_t HASH_LENGTH = 32;
        CLASS_CONSTANT size_t BLOCK_INFO_LENGTH = 80;

        Block_simple();
        size_t gethash(uint8_t dest[Block_simple::HASH_LENGTH]);
        bool loadblock(FILE* fp);
        bool loadblock(const uint8_t* buf);
        size_t get_prevhash(uint8_t dst[Block_simple::HASH_LENGTH]);
        bool mining(const uint8_t target[Block_simple::HASH_LENGTH]);
    private:
        struct {
            uint8_t Version[4];
            uint8_t hashPrevBlock[32];
            uint8_t hashMerkleRoot[32];
            uint8_t Time[4];
            uint8_t Bits[4];
            union {
                uint8_t inbytes[4];
                uint32_t in_int;
            } Nonce;
        } block_info;
        SHA256 sha256_ctx;
};

class BitChain {

public:
    CLASS_CONSTANT size_t HASH_LENGTH = 48;
    BitChain();
    size_t gethash(uint8_t dest[BitChain::HASH_LENGTH]);
    bool mining(const uint8_t last_hash[Block_simple::HASH_LENGTH]);
    uint32_t loadblock(FILE* fp);

private:
    list<Block_simple> blist;
    SHA384 sha384_ctx;

};

