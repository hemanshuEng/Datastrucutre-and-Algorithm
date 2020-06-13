#include <iostream>
#include <string>
/**
 * One Away :There are three Types of edits that can be performed on string: insert a character,
 * remove a character, or replace a character. Given two string write a function to check they are
 * one edit away
 *
 */
bool onEditReplace (const std::string &str1 ,const std::string &str2) {
    bool foundDifference = false;
    for(int i = 0 ; i < str1.length(); i++) {
        if(str1[i] != str2[i]) {
            if(foundDifference) {
                return false;
            }
            foundDifference = true;
        }
    }
    return true;
}
bool oneEditInsert(const std::string &str1 ,const std::string &str2 ) {
    int index1 = 0;
    int index2 = 0;
    while ( index2 < str2.length() && index1 < str1.length()) {
        if(str1[index1] != str2[index2]) {
            if(index1 != index2) {
                return false;
            }
            index2++;
        } else {
            index1++;
            index2++;
        }
    }
    return true;
}
bool oneEditAway(const std::string &str1 ,const std::string &str2 ) {
    if(str1.length() == str2.length()) {
        return onEditReplace(str1 , str2);
    } else if (str1.length() + 1 == str2.length()) {
        return oneEditInsert(str1 , str2);
    } else if (str1.length() - 1 == str2.length()) {
        return oneEditInsert(str2 , str1);
    }
    return false;
}


int main() {
    std::string str1 = "pale";
    std::string str2 = "male";
    std::cout << str1 << "  :  "<< str2 << " : " << std::boolalpha<<oneEditAway(str1, str2)<<std::endl;
    str1 = "pale";
    str2 = "ple";
    std::cout << str1 << "  :  "<< str2 << " : " << std::boolalpha<<oneEditAway(str1, str2)<<std::endl;
    str1 = "pale";
    str2 = "pales";
    std::cout << str1 << "  :  "<< str2 << " : " << std::boolalpha<<oneEditAway(str1, str2)<<std::endl;
    str1 = "pale";
    str2 = "bae";
    std::cout << str1 << "  :  "<< str2 << " : " << std::boolalpha<<oneEditAway(str1, str2)<<std::endl;
    return 0;
}
