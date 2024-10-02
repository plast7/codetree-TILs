#include <iostream>
#include <unordered_map>
using namespace std;

int N, K;
unordered_map<int, int> numbers;
int answer;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        numbers[x]++;
    }

    for (auto num : numbers) {
        int n1 = num.first;
        int n2 = K-n1;
        if (n1 == n2) {
            answer += num.second * (num.second-1);
        }
        else {
            answer += num.second * numbers[n2];
        }
    }

    cout << answer/2;
    return 0;
}