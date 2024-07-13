/*
//  Copyright 2024 Kasun Bamunuarachchi <knimantha817@gmail.com> <kasun.bamunuarachchi@outlook.com>
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http ://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
*/

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
