#include <iostream>
#include <string>
#include <vector>
/**
 * Palindrome Permutation : Given String , write a function to check if it is a permutation of a palindrome
 * A palidrome is word or phase that is same forward and backwords.
 * A permutation is a rearrangement of letters The palindrome does not need to be  limited to just dictionary words.
 */
/**
 *
 * @param str
 * @return bool
 */
bool  palindromePermutation(const std::string & str) {
    if(str.empty()) return false;
    std::vector<char> str_char(26);
    for(unsigned char it : str){
        if( it >= 'a' && it <= 'z') {
            it = it - 'a';
            str_char[it]++;
        }
        if( it >= 'A' && it <= 'Z') {
            it = it - 'A';
            str_char[it]++;
        }
    }
    int count = 0;
    for(char & it : str_char) {
        if((it % 2) != 0) {
           count++;
        }
    }
    return (count < 2);
}
int main() {
    std::string word = "Tact Coa";
    std::cout<<word<< " : "<< std::boolalpha<<palindromePermutation(word)<< std::endl;
    word = "";
    std::cout<<word<< " : "<< std::boolalpha<<palindromePermutation(word)<< std::endl;
    return 0;
}
