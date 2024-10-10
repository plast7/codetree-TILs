#include <iostream>
#include <vector>

using namespace std;

// 부품의 개수와 관계의 수를 저장할 변수
int num_parts, num_relations;

// 각 부품을 만들기 위해 필요한 부품의 수를 저장하는 배열
int part_requirements[200][200];

// 기본 부품의 개수를 저장하는 배열
int basic_part_count[200];

// 중간 부품인지 여부를 저장하는 배열
int is_intermediate[200];

// 기본 부품의 개수를 계산하는 함수
void calculateBasicParts(int part, int quantity) {
    // 현재 부품의 기본 부품 개수를 증가시킵니다.
    basic_part_count[part] += quantity;

    // 현재 부품을 만들기 위해 필요한 부품들을 순회합니다.
    for (int i = 1; i <= num_parts; i++) {
        // 필요한 부품이 있다면 재귀적으로 기본 부품의 개수를 계산합니다.
        if (part_requirements[part][i]) {
            calculateBasicParts(i, quantity * part_requirements[part][i]);
        }
    }
}

int main() {
    // 부품의 개수와 관계의 수를 입력받습니다.
    cin >> num_parts >> num_relations;

    // 각 부품의 관계를 입력받습니다.
    for (int i = 0; i < num_relations; i++) {
        int product, component, quantity;
        cin >> product >> component >> quantity;

        // 부품 관계를 저장합니다.
        part_requirements[product][component] = quantity;
        // 중간 부품임을 표시합니다.
        is_intermediate[product] = 1;
    }

    // 완제품을 만들기 위해 필요한 기본 부품의 개수를 계산합니다.
    calculateBasicParts(num_parts, 1);

    // 기본 부품의 번호와 개수를 출력합니다.
    for (int i = 1; i <= num_parts; i++) {
        // 중간 부품이 아닌 경우에만 출력합니다.
        if (!is_intermediate[i]) {
            cout << i << " " << basic_part_count[i] << endl;
        }
    }
    return 0;
}