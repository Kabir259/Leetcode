#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(){
        
    }

    int maxScore(vector<int>& cardPoints, int k) {
        // whenever such a question is given wherein you have choice to choose from left or the right
        // it wants you to look at the cropped subarray in the middle of the array from both the left and right sides
        // here since you want to maximise the sum of cards picked from left and right ends: 
        // if middle subarr + r&l= total arr sum then, max(r&l) => max(sum - middle subarr) => min(middle subarr) 
        // question: find the minimum sum subarray with length (n-k).

        int n = cardPoints.size();
        int netsum = 0;

        for(int i =0; i<n; i++){
            netsum+=cardPoints[i];
        }

        if(k==n) return netsum;

        int i = 0;
        int j = 0;
        int sum = 0;
        int mini = 1e9;

        while(j<n-k){
            sum+=cardPoints[j];
            j++;
        }

        mini = min(mini,sum);

        while(j<n){
            // mini = min(mini,sum); // WRONG place to put the minimiser. always put it after calculation and before incrementing idx.
            sum+=cardPoints[j];
            sum-=cardPoints[i];
            mini = min(mini,sum);
            j++;
            i++;
        }

        return netsum-mini;
    }
};