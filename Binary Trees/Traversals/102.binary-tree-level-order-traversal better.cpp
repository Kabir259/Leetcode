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

    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(root){
            q.push(root);
        }
        vector<vector<int>> ans;

        while(!q.empty()){
            int level = q.size();
            vector<int> v;

            for(int i = 0; i<level; i++){
                auto x = q.front();
                
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
                q.pop();
                v.push_back(x->val);
            }
            ans.push_back(v);
            v.clear();
        }

        return ans;

    }
    
};
// @lc code=end

