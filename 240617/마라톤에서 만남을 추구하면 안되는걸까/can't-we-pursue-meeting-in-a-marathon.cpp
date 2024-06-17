#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 100000
#define MAX_L 25000
#define MAX_C 25000

struct Runner {
    long long speed;
    long long position;
    int rank;
};

int n, l, c;
vector<Runner> runners;
int bit[MAX_N + 1];
int bitLen;

void bitInit(int n) {
    fill(bit, bit + n + 1, 0);
    bitLen = n;
}

int bitPrefixSum(int i) {
    int sum = 0;
    for (int j = i; j > 0; j -= (j & -j)) {
        sum += bit[j];
    }
    return sum;
}

void bitInc(int i) {
    for (int j = i; j <= bitLen; j += (j & -j)) {
        bit[j]++;
    }
}

bool compareModulus(const Runner& a, const Runner& b) {
    return a.position < b.position;
}

bool compareSpeed(const Runner& a, const Runner& b) {
    return a.speed < b.speed;
}

int main() {
    cin >> n >> l >> c;
    runners.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> runners[i].speed;
    }

    long long maxSpeed = 0;
    for (int i = 0; i < n; ++i) {
        maxSpeed = max(maxSpeed, runners[i].speed);
    }

    for (int i = 0; i < n; ++i) {
        runners[i].position = (l * c * runners[i].speed) % (c * maxSpeed);
    }

    sort(runners.begin(), runners.end(), compareModulus);
    
    int rank = 1;
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && runners[i].position == runners[j].position) {
            runners[j].rank = rank;
            ++j;
        }
        ++rank;
        i = j;
    }

    sort(runners.begin(), runners.end(), compareSpeed);
    
    bitInit(n);
    long long totalMeetings = 0;
    long long sumOfFloors = 0;

    for (int i = 0; i < n; ++i) {
        long long floor = (l * runners[i].speed) / maxSpeed;
        long long addition = floor * i - sumOfFloors - i + bitPrefixSum(runners[i].rank);
        
        totalMeetings += addition;
        sumOfFloors += floor;
        bitInc(runners[i].rank);
    }

    cout << totalMeetings << endl;
    return 0;
}