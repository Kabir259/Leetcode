#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> Solution::allFactors(int A) {
    int k = A;
    vector<int> ans;
    
    if(k==0){
        ans.push_back(0);
        return ans;
    }
    else if(k==1){
        ans.push_back(1);
        return ans;
    }
    for(int i = 1; i<=sqrt(k); i++){
        if(k%i==0){
            ans.push_back(i);
            if(i!=sqrt(k)){
                ans.push_back(k/i);
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
    
}