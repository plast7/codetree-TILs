#include <iostream>
#include <vector>

using namespace std;

int main() {
    int size, type;
    cin >> size >> type;

    // 파스칼의 삼각형을 저장할 2차원 벡터를 선언합니다.
    vector<vector<int>> pascalTriangle(size + 1, vector<int>(size + 1, 0));
    // 파스칼의 삼각형의 첫 번째 원소는 항상 1입니다.
    pascalTriangle[1][1] = 1;

    // 파스칼의 삼각형을 생성합니다.
    for (int i = 2; i <= size; i++) {
        for (int j = 1; j <= i; j++) {
            // 각 위치의 값은 바로 위의 값과 왼쪽 위의 값의 합입니다.
            pascalTriangle[i][j] = pascalTriangle[i - 1][j] + pascalTriangle[i - 1][j - 1];
        }
    }

    // 종류 1: 파스칼의 삼각형을 그대로 출력합니다.
    if (type == 1) {
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= i; j++) {
                cout << pascalTriangle[i][j] << " ";
            }
            cout << endl;
        }
    }
    // 종류 2: 파스칼의 삼각형을 거꾸로 뒤집고 가운데 정렬하여 출력합니다.
    else if (type == 2) {
        for (int i = size; i >= 1; i--) {
            // 가운데 정렬을 위해 앞에 공백을 추가합니다.
            for (int j = 0; j < size - i; j++) {
                cout << " ";
            }
            for (int j = 1; j <= i; j++) {
                cout << pascalTriangle[i][j] << " ";
            }
            cout << endl;
        }
    }
    // 종류 3: 파스칼의 삼각형을 시계방향으로 90도 회전하여 출력합니다.
    else if (type == 3) {
        for (int i = size; i >= 1; i--) {
            for (int j = size; j >= i; j--) {
                cout << pascalTriangle[j][i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}