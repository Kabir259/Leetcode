#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(){
        
    }

    int Solution::maxSubArray(const vector<int> &A) {
    
    int sum = 0;
    int maxi = INT_MIN;
    int ansStart;
    int ansEnd;
    int start;
    
    
    for(int i = 0; i<A.size(); i++){
        
        if(sum==0){
            start = i;
        }
        
        sum+= A[i];
        
        if(sum>maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        
        
        if(sum<0){
            sum = 0;
        }
    }
    
    return maxi;
    
    
}

};