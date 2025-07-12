#ifdef _DEBUG
//#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include "MultiHash.h"

const unsigned char* MultiHash::InputPreprocess(std::string TextInput, size_t* InputLength)
{
	const char* charInput = TextInput.c_str();
	*InputLength = TextInput.length();

	return reinterpret_cast<const unsigned char*>(charInput);
}

unsigned char* MultiHash::GenerateHash(const unsigned char* TextInput, size_t InputLength, unsigned char *hash)
{
	unsigned char* temphash =  SHA256(TextInput, InputLength, hash);

	std::stringstream ss;
	for (int i = 0; i < DIGEST_LEN; ++i) {
		ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
	}
	//std::string cvv = ss.str();
	std::cout << "Generated Hash intermediate: " << ss.str() << std::endl;

	return temphash;
}

std::stringstream MultiHash::CharToHexStream(unsigned char* HashInput)
{
	std::stringstream output;
	for (int i = 0; i < DIGEST_LEN; ++i) {
		output << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(HashInput[i]);
	}

	return output;
}

unsigned char* MultiHash::GetHashRaw(std::string TextInput)
{
	size_t InputSize;
	const unsigned char* ProcessedInput = InputPreprocess(TextInput, &InputSize);
	unsigned char* temphash = GenerateHash(ProcessedInput, InputSize, hash);

	return hash;
}

std::string MultiHash::GetHashAsHexString(std::string TextInput)
{
	unsigned char* HashOutput = GetHashRaw(TextInput);
	std::stringstream HashString = CharToHexStream(HashOutput);

	return HashString.str();
}