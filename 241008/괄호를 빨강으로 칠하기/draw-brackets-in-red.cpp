#include <iostream>
#include <cstdio>

using namespace std;

const int MOD = 2012;
const int MAXN = 1010;

int dp[MAXN]; // dp[i] represents the number of ways to reach balance i

int main() {
    int balance = 1; // Initial balance of parentheses
    dp[1] = 1;       // One way to have balance 1 at the beginning

    int ch;
    // Read characters one by one until balance drops to 0 or end of input
    while (balance > 0 && ((ch = cin.get()) == '(' || ch == ')')) {
        int dir = (ch == '(') ? 1 : -1; // Direction: +1 for '(', -1 for ')'
        balance += dir;                 // Update the balance

        if (dir == -1) {
            // If we read ')', we are closing a parenthesis
            for (int i = 1; i <= balance; ++i) {
                dp[i] = (dp[i] + dp[i + 1]) % MOD;
            }
        } else {
            // If we read '(', we are opening a parenthesis
            for (int i = balance; i >= 1; --i) {
                dp[i] = (dp[i] + dp[i - 1]) % MOD;
            }
        }

        dp[balance + 1] = 0; // Reset the dp value beyond current balance
    }

    // If balance is back to 1 (properly balanced), output dp[1], else output 0
    cout << ((balance == 1) ? dp[1] : 0) << endl;

    return 0;
}