#include <iostream>
using namespace std;
#define MAX_N 26

char line[MAX_N];

int main() {
    int n;
    cin >> n;

    // Reading input into the line array
    for (int i = 0; i < n; i++) {
        cin >> line[i];
    }

    int ex_time = 0;

    // Loop through each character in the line
    for (int i = 0; i < n; i++) {
        int correct_pos = line[i] - 'A'; // Determine the alphabet index

        // Case 1: If the character is to the left of its correct position
        if (correct_pos < i) {
            char temp_p = line[i];
            // Shift characters to the right to move temp_p to its correct position
            for (int j = i; j > correct_pos; j--) {
                line[j] = line[j - 1];
                ex_time++;  // Count each swap
            }
            line[correct_pos] = temp_p; // Place the character in the correct position
            /*for(int k = 0; k < n; k++) cout<< line[k]<< ' ';
                cout<< endl;*/
        }
        // Case 2: If the character is to the right of its correct position
        else if (correct_pos > i) {
            char temp_p = line[i];
            // Shift characters to the left to move temp_p to its correct position
            for (int j = i; j < correct_pos; j++) {
                line[j] = line[j + 1];
                ex_time++;  // Count each swap
            }
            line[correct_pos] = temp_p; // Place the character in the correct position
            /*for(int k = 0; k < n; k++) cout<< line[k]<< ' ';
                cout<< endl;*/
        }
    }for (int i = 0; i < n; i++) {
        int correct_pos = line[i] - 'A'; // Determine the alphabet index

        // Case 1: If the character is to the left of its correct position
        if (correct_pos < i) {
            char temp_p = line[i];
            // Shift characters to the right to move temp_p to its correct position
            for (int j = i; j > correct_pos; j--) {
                line[j] = line[j - 1];
                ex_time++;  // Count each swap
            }
            line[correct_pos] = temp_p; // Place the character in the correct position
            /*for(int k = 0; k < n; k++) cout<< line[k]<< ' ';
                cout<< endl;*/
        }
        // Case 2: If the character is to the right of its correct position
        else if (correct_pos > i) {
            char temp_p = line[i];
            // Shift characters to the left to move temp_p to its correct position
            for (int j = i; j < correct_pos; j++) {
                line[j] = line[j + 1];
                ex_time++;  // Count each swap
            }
            line[correct_pos] = temp_p; // Place the character in the correct position
            //for(int k = 0; k < n; k++) cout<< line[k]<< ' ';
                //cout<< endl;
        }
    }

    // Output the total number of swaps
    cout << ex_time << endl;

    return 0;
}