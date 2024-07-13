// multi-hash.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "openssl/sha.h"

//Inputs
const std::string PAN = "1234567890123456";
const std::string fixedValue = "072024";

//SHA parameters
unsigned char hash[SHA256_DIGEST_LENGTH];

int main() {
    // Example Primary Account Number (PAN)
    std::string PAN = "1234567890123456";
    std::string fixedValue = "SECRET_KEY";
    std::string input = PAN + fixedValue;

    unsigned char hash[SHA256_DIGEST_LENGTH];
    const char* charInput = input.c_str();
    const unsigned char* formattedCharInput = reinterpret_cast<const unsigned char*>(charInput);

    //SHA256_Init()
    unsigned char* encryptedData = SHA256(formattedCharInput, input.length(), hash);

    // Convert hash to hex string
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }

    std::string cvv = ss.str();
    // Display the generated CVV
    std::cout << "Generated CVV: " << cvv.substr(0, 3) << std::endl;

    return 0;
}
