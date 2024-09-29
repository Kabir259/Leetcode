#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(){
        
    }

    
    // Definition for binary tree
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    
    TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
        // Do not write main() function.
        // Do not read input, instead use the arguments to the function.
        // Do not print the output, instead return values as specified
        // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
        if(A==NULL){
            return NULL;
        }
        TreeNode* leftsol = getSuccessor(A->left,B);
        if(leftsol!=NULL){
            return leftsol;
        }
        else if(A->val>B){
            return A;
        }
        else{
            return getSuccessor(A->right,B);
        }
    }

};