#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() { // just sort it and take top k lmao
    int N, K;
    cin >> N >> K;

    vector<int> prices(N);
    for (int i = 0; i < N; ++i) {
        cin >> prices[i];
    }

    // Min-heap to store the K largest items
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Build the heap with the first K prices
    for (int i = 0; i < K; ++i) {
        minHeap.push(prices[i]);
    }

    // Process the remaining prices
    for (int i = K; i < N; ++i) {
        if (prices[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(prices[i]);
        }
    }

    // Sum the elements in the heap to get the result
    int maxStealAmount = 0;
    while (!minHeap.empty()) {
        maxStealAmount += minHeap.top();
        minHeap.pop();
    }

    // Output the maximum amount that can be stolen
    cout << maxStealAmount << endl;

    return 0;
}
