/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int targetSum, int pathsum, bool& ans){
        // while(pathsum!=targetSum){
        //     if(!root){
        //         return;
        //     }
        //     pathsum+=root->val;
        //     if(root->left){
        //         dfs(root->left,targetSum,pathsum,ans);
        //     }
        //     if(root->right){
        //         dfs(root->right,targetSum,pathsum,ans);
        //     }
        // }
        // ans = true;

        if(!root){
            return;
        }
        pathsum+= root->val;

        if(!root->left && !root->right && pathsum==targetSum){
            ans = true;
        }

        // pathsum+= root->val;

        dfs(root->left,targetSum,pathsum,ans);
        dfs(root->right,targetSum,pathsum,ans);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        dfs(root,targetSum,0,ans);
        return ans;

    }
};
// @lc code=end

