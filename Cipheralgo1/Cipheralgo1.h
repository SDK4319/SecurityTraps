#pragma once
#include<cstdint>

uint32_t getEncodedMessage(uint8_t* buffer) {
	static uint32_t hex_data[] = {
		0xe971de14,
		0xd87fc406,
		0xc67fc41a,
		0xc570c352,
		0x8a4ec216,
		0xda7fc216,
		0x8a78df01,
		0x8a70d50b,
		0xde3ed31b,
		0xcb72dc16,
		0xc479d500,
		0x863ee71a,
		0xd07fc217,
		0x8b3ee012,
		0xd96dc71c,
		0xd87a9007,
		0xc53ec41b,
		0xcf3ec31a,
		0xde7b901a,
		0xd93edd0a,
		0xd97bd301,
		0xcf6ac612,
		0xc66bd553,
		0xc3709017,
		0xcf7dd91e,
		0xcb729e53,
		0xed71df17,
		0x8a49df01,
		0xc13f0000, //last 2 byte is dummy data
		0x00000000
	};
	uint32_t len = 0;
	for (int i = 0; hex_data[i] != 0; i++) {
		uint32_t offset = i * 4;
		len = offset + 4;
		for (int j = 0; j < 4; j++) {
			buffer[offset + j] = hex_data[i] >> (8 * (3 - j)) & 0xFF;
		}
	}
	return len;
}

void encodeMessage(uint8_t* destMessage, char* sourceMessage, uint32_t key) {
	for (int i = 0; sourceMessage[i] != 0; i++) {
		destMessage[i] = sourceMessage[i] ^ ((key >> (8 * (i % 4))) % 0xFF);
	}
}

//inverse function of xor is xor
void decodeMessage(char* destMessage, uint8_t* sourceMessage, uint32_t key, uint32_t len) {	
	for (int i = 0; i < int(len); i++) {
		destMessage[i] = (char)(sourceMessage[i] ^ ((key >> (8 * (i % 4))) & 0xFF));
	}
}