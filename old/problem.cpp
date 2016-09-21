#include <iostream>
#include <string>
//#include "lucky_boy.hpp"

#define MAX_TRIES 100000

int main(int argc, char* argv[]){
	std::cout << "****** A work produced by XDSEC ******" << std::endl;
	std::cout << "Trying to make FULL use of your CPU :)" << std::endl;
	std::cout << "If you are lucky or rich enough, you can\n"
				 "get the flag directly. Or...you may want\n"
				 "to use Google and some other tools...     " << std::endl;
	int i = MAX_TRIES ;
	//LuckyChain* chain = new LuckyChain;		//load a lucky chain, and try to solve for 200 blocks
	do{
		std::cout << "Tried " << MAX_TRIES-i-- << "/" << MAX_TRIES << std::endl;
		//
		//LuckyHash oldhash = LuckyChain -> getHash();	//Get old hash of the last block
		//chain -> tryCalcBlock(500);					//Try to calculate 500 new blocks
		//
		//LuckyHash newhash = LuckyChain -> getHash();	//Get new hash of the last block
		//const char *ivHex = "DEADBEEF0BADC0DE8086012450301120"	//our iv
		//const char *keyHex = newhash;
		//const char *encStr = crypt.encryptStringENC("xdctf{N3v3r_buy_btc_unless_u_want_2_learn_crypt0graphy}")
		//
	}while(i);
}

