#include <iostream>

using namespace std;

int main() {
    // 변수 선언
    int arr[10];
    int sum = 0;
    int cnt = 0;
	
	// 10개의 정수를 입력받습니다.
    for(int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

	// 10개의 정수 중 250 이상의 수가 나올 때 까지의 수의 합계와 개수를 구합니다.
	for(int i = 0; i < 10; i++) {
        if(arr[i] >= 250) 
			break;
        sum += arr[i];
        cnt++;
    }
     
	// 평균을 구합니다.
    double avg = (double)sum / cnt;
 
    // 출력
    cout << fixed;
    cout.precision(1);
    cout << sum << " " << avg;
    
    return 0;
}