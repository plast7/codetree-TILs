#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;
    int len = str.length();
    int n;
    
    while(len > 1){
        len = str.length();
        cin >> n;

        if(n >= len){
            str.erase(len - 1, 1);
        }
        else
            str.erase(n, 1);
        
        cout << str << endl;
    }

    return 0;
}