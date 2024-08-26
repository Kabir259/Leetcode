#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(){
        
    }

    vector<int> Solution::maxset(vector<int> &A) {
    
    int n = A.size();
    
    vector<int> global;
    vector<int> v;
    long long maxSum = 0;
    long long sum = 0;
    long maxlen = 0;
    long len = 0;
    
    for(int i = 0; i<n; i++){
        
        if(A[i]<0){
            if (sum > maxSum || (sum == maxSum && len > maxlen)) {
                maxSum = sum;
                global = v;
                maxlen = len;
            }
            v.clear();
            sum = 0;
            len = 0;
            continue; // dont forget this becuase when you encounter a negative no YOU HAVE TO SKIP IT
        }
        
        sum+=A[i];
        v.push_back((int)A[i]);
        len++;
        
    }
    
    if (sum > maxSum || (sum == maxSum && len > maxlen)) {
        global = v;
    }

    
    return global;
    
    
}

    
};