#include <iostream>

using namespace std;

string s(int a, int b, int c) {
    if (a % 4 == 0) {
        if (a % 100 != 0 || a % 400 == 0) { 
            if ( b == 4 || b == 6 || b == 9 || b == 11) { 
                if (c > 30) return "-1"; 
            }
            else if (b == 2) { 
                if (c > 29) return "-1"; 
            }
            
            if (b == 3 || b == 4 || b == 5) return "Spring";
            else if (b == 6 || b == 7 || b == 8) return "Summer";
            else if (b == 9 || b == 10 || b == 11) return "Fall";
            else return "Winter";
            
        }
    }

    else { 
        if (b == 4 || b == 6 || b == 9 || b == 11) {
            if (c > 30) return "-1";
        }
        else if (b == 2) {
            if (c > 28) return "-1";
        }
        
        if (b == 3 || b == 4 || b == 5) return "Spring";
        else if (b == 6 || b == 7 || b == 8) return "Summer";
        else if (b == 9 || b == 10 || b == 11) return "Fall";
        else if(b==12 || b == 1 || b ==2 ) return "Winter";
        
    }
}
int main() {
    // 여기에 코드를 작성해주세요.
    int Y, M, D;
    cin >> Y >> M >> D;

    cout << s(Y, M, D);
    return 0;
}