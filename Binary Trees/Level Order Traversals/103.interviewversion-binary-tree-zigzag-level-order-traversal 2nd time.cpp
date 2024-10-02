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
        deque<TreeNode*> qu;

        if(root){
            qu.push_back(root);
        }

        // bool evenflag = true;
        int level = 0;

        bool leftToRight = true;

        while (!qu.empty()) {
            int levelsize = qu.size();
            vector<int> v(levelsize);

            for (int i = 0; i < levelsize; ++i) {
                if (leftToRight) {
                    TreeNode* node = qu.front();
                    qu.pop_front();
                    v[i] = node->val;
                    if (node->left) qu.push_back(node->left);
                    if (node->right) qu.push_back(node->right);
                } else {
                    TreeNode* node = qu.back();
                    qu.pop_back();
                    v[i] = node->val;
                    if (node->right) qu.push_front(node->right);
                    if (node->left) qu.push_front(node->left);
                }
            }
            ans.push_back(v);
            leftToRight = !leftToRight;  // Toggle the direction
        }
        return ans;

        // while(!qu.empty()){
        //     int levelsize = qu.size();
        //     vector<int> v;
        //     level++;

        //     if(level%2==0){
        //         auto x = qu.back();
        //         qu.pop_back();

        //         for(int i = 0; i<levelsize; i++){
        //             v.push_back(x->val);
        //             if(x->left) qu.push_front(x->left);
        //             if(x->right) qu.push_front(x->right);
        //         }
        //         ans.push_back(v);
        //         v.clear();
        //     }
        //     else{
        //         auto x = qu.front();
        //         qu.pop_front();

        //         for(int i = 0; i<levelsize; i++){
        //             v.push_back(x->val);

        //             if(x->right) qu.push_back(x->right);
        //             if(x->left) qu.push_back(x->left);
                    
        //         }
        //         ans.push_back(v);
        //         v.clear();
        //     }           

        // }

        // return ans;

    }
};
// @lc code=end

