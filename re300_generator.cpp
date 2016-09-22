#include "re300_generator.h"

int main(void){

    cout << "Opening files...";

    FILE* fp = fopen("newblocks", "rb");

    if (!fp){
        cout << "Error!";
        exit(-1);
    }

    cout << "Succeed.\n" <<
            "Loading blocks...";
    BitChain btc;
    uint32_t count = btc.loadblock(fp);
    cout << "Finished loading " << count << " blocks.\n";

    const static char fin_hash_s[]="00000000d66d589aa63025b450d32cc7679e3969d62b240b348332acc16eb582";
    cout << "Verifying " << count << " blocks, \n" <<
            "Using final hash: \n\t" <<
            fin_hash_s << "\n";
    uint8_t fin_hash[Block_simple::HASH_LENGTH];
    try{
        hex2bytes( fin_hash_s,
                   Block_simple::HASH_LENGTH,
                   fin_hash);
        bin_swaporder(fin_hash, Block_simple::HASH_LENGTH);
        btc.mining(fin_hash);
    } catch ( std::string *e){
        std::cout << *e << "\n";
    }
    cout << "Succeed.\n";

    uint8_t enc_hash[BitChain::HASH_LENGTH];
    char enc_hash_s[1+2*BitChain::HASH_LENGTH]={0};
    
    cout << "Generating chain hash:\n\t";
    btc.gethash(enc_hash);
    bytes2hex( enc_hash,
               BitChain::HASH_LENGTH,
               enc_hash_s);
    cout << enc_hash_s << endl;

    cout << "Generating second hash:\n\t";
    union {
        struct {
            uint8_t key[flag_key_len];
            uint8_t iv [flag_iv_len];
        } dict;
        uint8_t val[flag_key_len+flag_iv_len];
    } crypto_params;
    SHA384 sha384_ctx;
    sha384_ctx.init();
    sha384_ctx.update(enc_hash, BitChain::HASH_LENGTH);
    sha384_ctx.final(crypto_params.val);
    memset(enc_hash_s, 0, 1+2*BitChain::HASH_LENGTH);    
    bytes2hex(crypto_params.val,
              BitChain::HASH_LENGTH,
              enc_hash_s);
    cout << enc_hash_s << endl;

    cout << "Crypto Parameters:\n\t";
    long_xor(crypto_params.val, enc_hash, BitChain::HASH_LENGTH);
    memset(enc_hash_s, 0, 1+2*BitChain::HASH_LENGTH);
    bytes2hex(crypto_params.dict.iv,
              flag_iv_len,
              enc_hash_s);
    cout << "IV  = " << enc_hash_s << "\n\t";
    memset(enc_hash_s, 0, 1+2*BitChain::HASH_LENGTH);
    bytes2hex(crypto_params.dict.key,
              flag_key_len,
              enc_hash_s);
    cout << "KEY = " << enc_hash_s << "\n";

    cout << "Start to generate encrypted flag..." << endl;

    const static  char preset_flag[] = "xdctf{N3v3r_buy_btc_un1es_u_want_2_know_crypt0_lol_padding_now}";
    // make length-1 for end of string
    if ( strlen(preset_flag) != flag_len-1 ){
        cout << "ERROR FLAG LENGTH IS INCORRECT\n";
        exit(-2);
    }


    return 0;    
}