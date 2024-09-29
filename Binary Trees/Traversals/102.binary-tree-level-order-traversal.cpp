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
        queue<TreeNode*> qu; // You are passing an entire class into the qu not the constructor
        
        vector<vector<int>> ans;

        if(root==nullptr){
            return ans;
        }



        qu.push(root);

        while(!qu.empty()){
            auto x = qu.front();
            int s = qu.size();

            

            vector<int> v;



            for(int i = 0; i<s; i++){
                auto node = qu.front();
                v.push_back(node->val);
                qu.pop();

                if(node->left!=nullptr){
                    qu.push(node->left);
                }

                if(node->right!=nullptr){
                    qu.push(node->right);
                }

                

            }


            ans.push_back(v);

        }

        return ans;
    }
};
// @lc code=end

