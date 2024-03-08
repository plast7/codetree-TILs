#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 양수 저장 벡터
vector<int> positive;

// 음수 저장 벡터
vector<int> negative;

// 0 의 개수
int zero_count;

// 수열 최댓값
int result;

// 수열 최댓값 출력 함수
int greedy(){

    // 양수 저장 벡터 내림차순 정렬
    sort(positive.begin(), positive.end(), greater<int>());
    // 음수 저장 벡터 오름차순 정렬
    sort(negative.begin(), negative.end(), less<int>());

    // 내림차순 정렬된 양수 저장 벡터의 요소들을 두 묶음씩 곱한 뒤, 결과값에 추가
    for (int i=0; i<positive.size()-(positive.size()%2); i +=2){
        // i 번째 요소와 i+1 번째 요소를 곱한 뒤, 결과값에 추가
        result += positive[i] * positive[i+1];
    }

    // 양수 저장 벡터가 홀수일 경우, 마지막 요소가 묶음에서 제외되었기 떄문에, 마지막 요소를 결과값에 추가
    if (positive.size() % 2 == 1){
        result += positive.back();
    }

    // 오름차순 정렬된 음수 저장 벡터의 요소들을 두 묶음씩 곱한 뒤, 결과값에 추가
    for (int i=0; i<negative.size()-(negative.size()%2); i +=2){
        // i 번째 요소와 i+1 번째 요소를 곱한 뒤, 결과값에 추가
        result += negative[i] * negative[i+1];
    }

    // 음수 저장 벡터가 홀수일 경우, 마지막 요소가 묶음에서 제외되었기 떄문에, 마지막 요소를 결과값에 추가
    if (negative.size() % 2 == 1){

        // 만약, 수열에 0 이 존재하지 않는다면, 음수 저장 벡터의 마지막 요소를, 그대로 결과값에 추가
        if (zero_count == 0){
            result += negative.back();
        }
        // 만약, 수열에 0 이 존재한다면, 음수 저장 벡터의 마지막 요소와 0 을 곱할 수 있으므로, 상쇄 가능   
    }

    // 수열 최댓값 반환
    return result;

}

int main(){

    // 수열의 개수
    int n;
    cin >> n;

    // 수열 요소 입력
    for (int i=0; i<n; ++i){
        int number;
        cin >> number;

        // 숫자가 1 보다 크다면, 양수 저장 벡터에 저장
        if (number >1){
            positive.push_back(number);
        }
        // 숫자가 1 이라면, 수열 최댓값에 추가
        else if (number == 1){
            result += 1;
        }
        // 숫자가 0 이라면, 0 의 개수 추가
        else if (number == 0){
            zero_count += 1;
        }
        // 숫자가 0 보다 작다면, 음수 저장 벡터에 저장
        else{
            negative.push_back(number);
        }
    }

    // 수열 최댓값 출력
    cout << greedy() << endl;

}