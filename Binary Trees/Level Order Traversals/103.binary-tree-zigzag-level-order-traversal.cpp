/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> qu;

        if(root){
            qu.push(root);
        }

        bool evenflag = true;

        while(!qu.empty()){
            int level = qu.size();
            vector<int> v;
            for(int i = 0; i<level; i++){
                auto x = qu.front(); 
                qu.pop();
                v.push_back(x->val);
                
                if(x->left) qu.push(x->left);
                if(x->right) qu.push(x->right);
            }
            if(evenflag){
                ans.push_back(v);
                evenflag = false;
            }
            else if(!evenflag){
                reverse(v.begin(),v.end());
                evenflag = true;
                ans.push_back(v);
            }
            v.clear();

        }

        return ans;

    }
};
// @lc code=end

