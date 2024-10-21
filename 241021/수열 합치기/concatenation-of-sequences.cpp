#include <iostream>
#include <algorithm>
using namespace std;

// 수열 A와 B를 저장할 배열을 선언합니다.
int a[100005];
int b[100005];

// 합쳐진 수열을 저장할 배열을 선언합니다.
int c[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 수열 A와 B의 크기를 입력받습니다.
    int sizeA, sizeB;
    cin >> sizeA >> sizeB;
    
    // 수열 A의 원소들을 입력받습니다.
    for(int i = 0; i < sizeA; i++)
        cin >> a[i];
    
    // 수열 B의 원소들을 입력받습니다.
    for(int i = 0; i < sizeB; i++)
        cin >> b[i];
    
    // 수열 A와 B를 각각 오름차순으로 정렬합니다.
    sort(a, a + sizeA);
    sort(b, b + sizeB);
    
    int indexA = 0, indexB = 0, indexC = 0;
    
    // 두 수열을 오름차순으로 합칩니다.
    while(indexA < sizeA && indexB < sizeB) {
        if(a[indexA] <= b[indexB]) {
            c[indexC++] = a[indexA++];
        }
        else {
            c[indexC++] = b[indexB++];
        }
    }
    
    // 수열 A에 남은 원소들을 배열 c에 추가합니다.
    while(indexA < sizeA) {
        c[indexC++] = a[indexA++];
    }
    
    // 수열 B에 남은 원소들을 배열 c에 추가합니다.
    while(indexB < sizeB) {
        c[indexC++] = b[indexB++];
    }
    
    // 합쳐진 수열 c의 원소들을 출력합니다.
    for(int i = 0; i < indexC; i++) {
        cout << c[i] << " ";
    }
    
    return 0;
}