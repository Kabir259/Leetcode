/*
 * @lc app=leetcode id=865 lang=cpp
 *
 * [865] Smallest Subtree with all the Deepest Nodes
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
    int deepestlevel = 0;
    TreeNode* connecting_point;

    int dfs(TreeNode* root, int h){
        if(!root){
            return h;
        }

        int l = dfs(root->left,h+1);
        int r = dfs(root->right,h+1);

        int currheight = max(l,r);

        if(currheight>=deepestlevel){
            deepestlevel=currheight;
            if(l==currheight && r==currheight) {
                connecting_point=root;
            }
        }

        // void counterpart code is done. but as it is int, you are expected to 
        //return the trivially expected ans that is max height of the the tree at root

        return currheight;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int h =dfs(root,0);
        return connecting_point;
    }
};
// @lc code=end

