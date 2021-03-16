/*
	https://www.securitytraps.pl/challs/cipheralgo1/
*/

#include "Cipheralgo1.h"
#include<iostream>

using namespace std;

char originalMessage[256] = {};
uint8_t encodedMessage[256] = {};
uint32_t master_key = 0x73B01EAA;

int main() {
	uint32_t len = getEncodedMessage(encodedMessage);
	len -= 2; //2byte dummy data
	decodeMessage(originalMessage, encodedMessage, master_key, len);
	std::cout << originalMessage;
	return 0;
}