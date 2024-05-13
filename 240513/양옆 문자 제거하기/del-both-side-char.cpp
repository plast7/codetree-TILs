#include <iostream>
#include <string>
using namespace std;

int main() {
    // 문자열을 정의합니다.
	string str;
	
	// 문자열을 입력받습니다.
	cin >> str;
	
	// 문자열의 길이를 구합니다.
	int len = str.length();
	
  	// 앞에서 2번째 원소를 제거합니다. (이때 문자열의 길이가 1 감소하는것을 반드시 기억합니다)
	str.erase(1, 1);
	len--;
	
	// 뒤에서 2번째 원소를 제거합니다.
	str.erase(len - 2, 1);
	len--;
	
	// 앞에서 2번째, 뒤에서 2번째 원소가 제거된 문자열을 출력합니다.
	cout << str;
	
    return 0;
}