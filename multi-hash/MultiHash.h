#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "openssl/sha.h"

class MultiHash {
public:
	std::string GetHashAsHexString(std::string TextInput);
	unsigned char* GetHashRaw(std::string TextInput);
private:
	const unsigned char* InputPreprocess(std::string TextInput, size_t* InputLength);
	unsigned char* GenerateHash(const unsigned char* TextInput, size_t InputLength);
	std::stringstream CharToHexStream(unsigned char *HashInput);
};