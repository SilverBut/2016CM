#pragma once
#include "common.h"
#include "sha256.h"

class Block_simple {
    public:
        CLASS_CONSTANT size_t HASH_LENGTH = 32;
        CLASS_CONSTANT size_t BLOCK_INFO_LENGTH = 80;

        Block_simple();
        size_t gethash(uint8_t dest[Block_simple::HASH_LENGTH]);
        bool loadblock(FILE* fp);
        bool loadblock(const uint8_t* buf);
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
