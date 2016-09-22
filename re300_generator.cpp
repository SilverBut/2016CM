#include "re300_generator.h"

int main(void){
    Block_simple testblock;
    FILE* fp = fopen("newblocks", "rb");
    testblock.loadblock(fp);
    fclose(fp);

    uint8_t testhash[Block_simple::HASH_LENGTH];
    char testhashs[1+2*Block_simple::HASH_LENGTH];
    memset(testhashs, 0, 1+2*Block_simple::HASH_LENGTH);
    testblock.gethash(testhash);
    bin_swaporder(testhash, Block_simple::HASH_LENGTH);
    bytes2hex(testhash, Block_simple::HASH_LENGTH, testhashs);
    printf("Verify %s", testhashs);
   /*
    uint8_t original_hash[Block_simple::HASH_LENGTH];
    hex2bytes("00000000000000001e8d6829a8a21adc5d38d0a473b144b6765798e61f98bd1d",
            32,
            original_hash);
    bytes2hex(original_hash, Block_simple::HASH_LENGTH, testhashs);
    printf("Old: %s\n", testhashs);



    Block_simple testblock;
    uint8_t testhash[Block_simple::HASH_LENGTH];
    hex2bytes("01000000", 4, (testblock.block_info.Version));
    hex2bytes("81cd02ab7e569e8bcd9317e2fe99f2de44d49ab2b8851ba4a308000000000000", 
        32, 
        (testblock.block_info.hashPrevBlock));

    hex2bytes("e320b6c2fffc8d750423db8b1eb942ae710e951ed797f7affc8892b0f1fc122b", 
    32, 
    (testblock.block_info.hashMerkleRoot));
    hex2bytes("c7f5d74d", 4, (testblock.block_info.Time));
    hex2bytes("f2b9441a", 4, (testblock.block_info.Bits));
    hex2bytes("42a14695", 4, (testblock.block_info.Nonce.inbytes));


    for ( unsigned int i = 0 ; i <= 0xFFFFFFFF ; i++ ){
        testblock.block_info.Nonce.in_int = i;
        testblock.gethash(testhash);
        bin_swaporder(testhash, Block_simple::HASH_LENGTH);
        if (!memcmp(testhash,
                     original_hash, 
                     Block_simple::HASH_LENGTH))
        {
            printf("%p\n", i);
            break;
        }
        if ( (i>=0x9546a140 && i>=0x9546a150) || ( i >= 0x42a14690 && i <= 0x42a146a0 ) )
        {
            printf("%p\n", i);
            break
        }

    }

    bytes2hex(testhash, Block_simple::HASH_LENGTH, testhashs);
    printf("New: %s\n", testhashs);


    printf("%d", memcmp(testhash, original_hash, Block_simple::HASH_LENGTH));
*/
    return 0;

    
}