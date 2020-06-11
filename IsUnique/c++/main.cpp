#include <iostream>
#include <vector>
#include <string>
#include <map>

bool isUniqueCharsNoDs(const std::string &str) {
    for (int i = 0; i < str.length() -1; i++) {
        for(int j = i+1; j < str.length(); j++) {
            if(str[i] == str[j]) {
                return false;
            }
        }
    }
    return true;
}

bool isUniqueChars(const std::string &str) {
    if (str.length() > 128) {
        return false;
    }
    std::vector<bool> char_set(128);
    for (int i = 0; i<str.length(); i++) {
        if(char_set[str[i]]){
            return false;
        }
        char_set[str[i]] = true;
    }
    return true;
}

int main() {
    std::vector<std::string> words = {"abcde", "hello", "apple", "kite", "eadle"};
    for (auto word : words) {
        std::cout << word << std::string(": ") << std::boolalpha << isUniqueCharsNoDs(word) <<std::endl;
    }
    for (auto word : words) {
        std::cout << word << std::string(": ") << std::boolalpha << isUniqueChars(word) <<std::endl;
    }
    return 0;
}
