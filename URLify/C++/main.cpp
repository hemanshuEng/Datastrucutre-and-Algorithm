#include <iostream>
#include <string>
int countOfSpace(std::string url){
    int count = 0;
    for (int i= 0; i < url.length(); i++) {
        if(url[i] == ' ') {
           count++;
        }
    }
    return count;
}
void replaceSpaces( std::string &url) {
    int numberOfSpace = countOfSpace(url);
    int newIndex = url.length() + numberOfSpace*2;
    int originalLength = url.length()-1;
    url.resize(newIndex, '$');
    for (int j = originalLength ,i = newIndex -1; j >= 0 ; --j ) {
        if( url[j] == ' ') {
            url[i--] = '0';
            url[i--] = '2';
            url[i--] = '%';
        } else {
            url[i--] = url[j];
        }
    }
}
int main() {
    std::string  str = "H ello Worl d";
    replaceSpaces(str);
    std::cout << str << std:: endl;
    return 0;
}
