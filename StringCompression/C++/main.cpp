#include <iostream>
#include <string>
/**
 * String Compression: Implement a method to perform basic string compression using the counts
 * of repeated characters. for example, the string aabcccccaa would become a2b1c5a3. if the
 * "compressed" string would not become smaller than the original string, your method should return
 * the original string. You can assume the string has only uppercase and lowecase letters(a-z)
 *
 */
unsigned int countCompression(const std::string &str) {
    unsigned int compressedLength = 0;
    unsigned int countConsecutive = 0;
    for(int i = 0; i < str.length(); i++) {
        countConsecutive++;
        if(i + 1> str.length() || str[i] != str[i+1]) {
            compressedLength += 1 + std::to_string(countConsecutive).length();
            countConsecutive = 0;
        }
    }
    return compressedLength;
}

std::string compress(const std::string &str) {
    std::string compressString;
    unsigned int countConsecutive = 0;
    for(int i = 0; i < str.length(); i++) {
        countConsecutive++;
        if(i + 1> str.length() || str[i] != str[i+1]) {
            compressString += str[i] + std::to_string(countConsecutive);
            countConsecutive = 0;
        }
    }
    return compressString;
}

int main() {
    std::string inputString;
    std::cout << "Enter string: " << std::endl;
    std::cin >> inputString;
    if(countCompression(inputString) >= inputString.length()) {
        std::cout << "string cannot compressed :" << inputString<< std::endl;
    } else {
        std::cout << "string can be compressed" << std::endl << inputString << " compress to :" << compress(inputString);
    }
    return 0;
}
