#include <iostream>
#include <string>
#include <algorithm>
#include <map>

/**
 * O(n)
 * @param str1
 * @param str2
 * @return bool
 */
bool arePremutaion_1(std::string str1 , std::string str2) {
    if(str1.length() != str2.length()) {
        return false;
    }
    std::map <char,int> count;
    for (int i = 0; i < str1.length(); i++) {
        count[str1[i]]++;
    }
    for(int i = 0; i < str2.length(); i++) {
        count[str2[i]]--;
        if(count[str2[i]]<0)
            return false;
    }
    return true;
}
/**
 * O(n)
 * @param str1
 * @param str2
 * @return
 */
bool arePremutaion_2(std::string str1 , std::string str2) {
    if(str1.length() != str2.length()) {
        return false;
    }
    std::sort(str1.begin(),str1.end());
    std::sort(str2.begin(),str2.end());
    for(int i = 0 ; i < str1.length(); i++) {
        if( str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}
int main() {
    std::string str1 = "llllll";
    std::string str2 = "lllllw";
    if(arePremutaion_1(str1, str2)) {
        std::cout<< str1 << " and " << str2 << " are permutation of each other" << std::endl;
    } else {
        std::cout<< str1 << " and " << str2 << " are not permutation of each other" << std::endl;
    }
    if(arePremutaion_2(str1, str2)) {
        std::cout<< str1 << " and " << str2 << " are permutation of each other" << std::endl;
    } else {
        std::cout<< str1 << " and " << str2 << " are not permutation of each other" << std::endl;
    }
    return 0;
}
