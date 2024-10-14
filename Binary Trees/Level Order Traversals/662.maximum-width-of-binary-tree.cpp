/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// @lc code=start

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return NULL;
        int ans  =0;
        queue<pair<TreeNode*,int>> qu;
        qu.push({root,0});

        while(!qu.empty()){
            int l = qu.size();
            int startIDX = qu.front().second;
            int backIDX = qu.back().second;
            ans = max(ans, backIDX-startIDX+1);

            for(int i = 0; i<l; i++){
                auto [x,idx] = qu.front();
                qu.pop();
                if(x->left) qu.push({x->left,2*idx+1});
                if(x->right) qu.push({x->right,2*idx+2});
                
            }
        }

        

    }
};
// @lc code=end

