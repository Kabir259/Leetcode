#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int countSecondsToStabilize(string s) {
    int maxSeconds = 0;
    int countZero = 0; // Count of 0s before a 1 is encountered

    // Traverse the string
    for (char ch : s) {
        if (ch == '0') {
            countZero++; // Increment count of 0s
        } else { // ch == '1'
            // Update maxSeconds to the maximum count of 0s before this 1
            maxSeconds = max(maxSeconds, countZero);
        }
    }
    
    return maxSeconds;
}

int main() {
    string s;
    cout << "Enter the binary string: ";
    cin >> s; // Input the binary string
    
    int seconds = countSecondsToStabilize(s);
    cout << "The number of seconds until stabilization: " << seconds << endl;

    return 0;
}
