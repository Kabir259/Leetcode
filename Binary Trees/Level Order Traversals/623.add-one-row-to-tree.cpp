/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1){
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }

        if(!root){
            return NULL;
        }

        queue<TreeNode*> qu;
        int level = 0;
        qu.push(root);

        while(!qu.empty()){
            level++;

            if(level==depth-1){
                break;
            }

            int levelsize = qu.size();
           

            for(int i = 0; i<levelsize; i++){
                auto x = qu.front();
                qu.pop();

                if(x->left) qu.push(x->left);
                if(x->right) qu.push(x->right);
            }
        } 
        // this while loop breaks when we are at desired level

        // this also leaves the queue filled, not popped by the row;
        // so for #(elts) in queue, add that may val nodes as is new children in those locations
        // preserve child connections for newly added nodes

        int n = qu.size();

        while(n--){
            auto x = qu.front();
            qu.pop();

            // if(x->left) { // dont just target existing left rights, if they dont exist, STILL you have to insert TreeNode(val) as a child
                TreeNode* new_left = new TreeNode(val);
                new_left->left = x->left;
                x->left = new_left;
            // }
            // if(x->right){
                TreeNode* new_right = new TreeNode(val);
                new_right->right = x->right;
                x->right = new_right;
            // } 
        }
        return root;
    }
};
// @lc code=end

