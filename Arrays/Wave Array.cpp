#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(){
        
    }

    vector<int> Solution::wave(vector<int> &A) {
    int n = A.size();
    sort(A.begin(),A.end());
    vector<int> ret;
    int i = 0;
    
    if(n%2==0){
        while(i<n-1){
            int a = A[i];
            int b = A[i+1];
            ret.push_back(b);
            ret.push_back(a);
            i+=2;        
        }
    }
    else if(n%2==1){
        while(i<n-2){
            int a = A[i];
            int b = A[i+1];
            ret.push_back(b);
            ret.push_back(a);
            i+=2;        
        }
        ret.push_back(A[n-1]);
    }
    
    return ret;
    
    
}

};