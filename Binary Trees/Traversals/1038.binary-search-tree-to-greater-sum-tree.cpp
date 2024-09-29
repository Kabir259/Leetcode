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
    void inorder(TreeNode* root, int& temp){
        if(!root) return;
        inorder(root->right,temp);
        root->val += temp;
        temp = root->val;
        inorder(root->left,temp);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        // dont write iterative code of inorder for this
        // inorder must happen in reverse for this code

        int temp = 0;
        inorder(root,temp);

        return root;
    
    }
};
// @lc code=end

