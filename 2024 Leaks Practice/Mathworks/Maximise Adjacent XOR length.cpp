#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
typedef vector<ll> vll;

ll longestSubsequenceWithXorK(ll n, ll k, vll prices) {
    if (n < 2) {
        return -1; // If there's only one item, a subsequence of adjacent elements is impossible.
    }

    // Initialize the DP array to track the longest subsequence lengths
    vll dp(n, 0); // Start with zero-length subsequences
    ll maxLength = 0; // To store the maximum length of a valid subsequence

    // Fill the DP array
    for (ll i = 1; i < n; ++i) {
        for (ll j = 0; j < i; ++j) {
            // Check if the XOR condition is satisfied
            if ((prices[j] ^ prices[i]) == k) {
                dp[i] = max(dp[i], dp[j] + 1); // Extend the subsequence
            }
        }
        maxLength = max(maxLength, dp[i]); // Update the maximum length found
    }

    // If maxLength is greater than or equal to 1, we found at least one valid subsequence
    return maxLength >= 1 ? maxLength + 1 : -1; // +1 to count the current element itself
}

int main() {
    ll n = 5;
    ll k = 1;
    vll prices = {3,2,4,3,5};

    ll result = longestSubsequenceWithXorK(n, k, prices);
    cout << result << endl; // 3

    return 0;
}
