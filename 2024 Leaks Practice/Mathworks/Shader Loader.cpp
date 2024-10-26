#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int minIdleness(string shader, int switchCount) {
    vector<int> segments;
    char currentChar = shader[0];
    int currentCount = 1;

    // Step 1: Identify segments
    for (size_t i = 1; i < shader.size(); ++i) {
        if (shader[i] == currentChar) {
            currentCount++;
        } else {
            segments.push_back(currentCount);
            currentChar = shader[i];
            currentCount = 1;
        }
    }
    segments.push_back(currentCount); // Add the last segment

    // Step 2: Use a max heap to manage segments
    priority_queue<int> maxHeap(segments.begin(), segments.end());

    // Step 3: Reduce the largest segment using the switches
    while (switchCount > 0 && !maxHeap.empty()) {
        int largest = maxHeap.top();
        maxHeap.pop();

        if (largest > 1) {
            largest--; // Reduce the largest segment
            switchCount--; // Use one switch
            maxHeap.push(largest);
        } else {
            break; // No point in reducing further if it's 1
        }
    }

    // The remaining maximum in the heap is the minimum idleness
    return maxHeap.empty() ? 0 : maxHeap.top();
}

int main() {
    string shader;
    int switchCount;
    
    cout << "Enter the shader string (a/b): ";
    cin >> shader;
    cout << "Enter the maximum number of switches allowed: ";
    cin >> switchCount;

    int minIdlenessValue = minIdleness(shader, switchCount);
    cout << "The minimum possible idleness is: " << minIdlenessValue << endl;

    return 0;
}
