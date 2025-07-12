#pragma once

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "openssl/sha.h"

#define DIGEST_LEN SHA256_DIGEST_LENGTH

class MultiHash {
public:
	std::string GetHashAsHexString(std::string TextInput);
	unsigned char* GetHashRaw(std::string TextInput);
private:
	unsigned char hash[DIGEST_LEN];
	const unsigned char* InputPreprocess(std::string TextInput, size_t* InputLength);
	unsigned char* GenerateHash(const unsigned char* TextInput, size_t InputLength, unsigned char* hash);
	std::stringstream CharToHexStream(unsigned char *HashInput);
};