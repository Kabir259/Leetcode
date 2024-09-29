/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    void dfs(TreeNode* root, int targetSum, 
    int pathSum, vector<int> path, vector<vector<int>>& ans){
        if(!root){
            return;
        }

        path.push_back(root->val);
        pathSum+=root->val;

        if(!root->left && !root->right && pathSum==targetSum){
            ans.push_back(path);
        }

        dfs(root->left,targetSum,pathSum,path,ans);
        dfs(root->right,targetSum,pathSum,path,ans);

    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        int pathSum = 0;
        dfs(root,targetSum,pathSum,path,ans);
        return ans;
    }
};
// @lc code=end

