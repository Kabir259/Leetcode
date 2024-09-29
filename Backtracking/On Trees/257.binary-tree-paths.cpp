/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    void dfs(TreeNode* root, string temp, vector<string> &ans){
        // DONT PASS &TEMP AS THEN YOU WOULD BE INCOSISTENTLY CHANGING TEMP ALWAYS. 
        // YOU WANT EACH BRANCH TO RECIEVE ITS OWN INDEPENDENT FRESH TEMP WITHOUT CHANGE FROM OTHER BRANCHES

        if(!root) return;
        if(!root->left && !root->right){ // at leaf
            temp+=to_string(root->val);
            ans.push_back(temp);
        }

        temp += to_string(root->val)+"->";
        if(root->left){
            dfs(root->left,temp,ans);
        }
        if(root->right){
            dfs(root->right,temp,ans);
        }

    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp = "";
        dfs(root,temp,ans);
        return ans;
    }
};
// @lc code=end

