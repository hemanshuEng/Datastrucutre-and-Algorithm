#include <iostream>
#include <string>
/**
 * String Rotation : Assume you have a method isSubstring which check if one word is a substring
 * of another. Given two string, s1 and s2, write code to check if s2 is a rotation of s1 using only
 * call to isSubstring(e.g. "waterbottle" is a rotation of "erbottlewat")
 */
 bool isSubstring(const std::string &str1 ,const std::string &str2) {
    return str1.find(str2) != std::string::npos;
 }
 bool isRotation(const std::string &originalString,const std::string &rotatedString) {
     int length = originalString.length();
     if (length == rotatedString.length() && length > 0) {
         std::string s1s1 = originalString + originalString;
         return isSubstring(s1s1,rotatedString);
     }
     return false;
 }
int main() {
    std::string s1, s2;
    std::cout << "Enter string 1 : ";
    std::cin >> s1;
    std::cout << "Enter string 2 : ";
    std::cin >> s2;
    if ( isRotation(s1, s2) ) {
        std::cout << "Yes! " << s2 << " is rotation of " << s1 << std::endl;
    } else {
        std::cout << "No! " << s2 << " is not a rotation of " << s1 << std::endl;
    }
    return 0;
}
