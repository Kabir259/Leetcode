#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(){
        
    }

    void Solution::rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int>> B(A.size(),vector<int>(A[0].size()));
    
    for(int i = 0; i < A.size(); i++){
        for(int j = i+1; j < A[0].size(); j++){
            swap(A[i][j], A[j][i]);
        }
    }
    
    // Reverse each row
    for(int i = 0; i < A.size(); i++){
        reverse(A[i].begin(), A[i].end());
    }
}

};