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
	do{
		std::cout << "Tried " << MAX_TRIES-i-- << "/" << MAX_TRIES << std::endl;

	}while(i);
//	LuckyChain* chain = new LuckyChain;
}

