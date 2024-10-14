#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int A, int B, vector<int>& ans){
    if(i>B){
        return;
    }
    if(i<=B && i>=A){
        ans.push_back(i);
    }
    int lastdigit = i%10;
    if(lastdigit!=0){
        int prev = i*10 + lastdigit-1;
        dfs(prev, A,B,ans);
    }
    if(lastdigit!=9){
        int next = i*10 + lastdigit+1;
        dfs(next, A,B,ans);
    }
}
// // here i tried to do it like leetcode 127 . dont do it like that


class Solution {
public:
    vector<int> stepnum(int A, int B);
};

vector<int> Solution::stepnum(int A, int B) {
    vector<int> ans;
    for(int i = 1; i<=9; i++){ // dont start from 0
        dfs(i, A, B , ans);
    }
    if(A==0){
        ans.push_back(0);
    }
    sort(ans.begin(),ans.end());
    return ans;
}


