#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {    string str1,str2;

    while(cin >> str1){
        str2 += str1;
    }
    cout << str2;
    
    return 0;
}