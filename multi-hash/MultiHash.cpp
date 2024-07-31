#include "MultiHash.h"

std::string MultiHash::GetHashAsHexString(std::string TextInput)
{
	std::stringstream HashString = this->CharToHexStream(GetHashRaw(TextInput));
	return HashString.str();
}

unsigned char* MultiHash::GetHashRaw(std::string TextInput)
{
	size_t InputSize;
	const unsigned char* ProcessedInput = this->InputPreprocess(TextInput, &InputSize);
	return GenerateHash(ProcessedInput,InputSize);
}

const unsigned char* MultiHash::InputPreprocess(std::string TextInput, size_t* InputLength)
{
	const char* charInput = TextInput.c_str();
	*InputLength = TextInput.length();
	return reinterpret_cast<const unsigned char*>(charInput);
}

unsigned char* MultiHash::GenerateHash(const unsigned char* TextInput, size_t InputLength)
{
	unsigned char hash[SHA256_DIGEST_LENGTH];
	return SHA256(TextInput, InputLength, hash);
}

std::stringstream MultiHash::CharToHexStream(unsigned char* HashInput)
{
	std::stringstream output;
	for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
		output << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(HashInput[i]);
	}
	return output;
}
