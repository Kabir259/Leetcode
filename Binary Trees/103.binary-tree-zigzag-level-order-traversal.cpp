#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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
        queue<TreeNode*> qu; // You are passing an entire class into the qu not the constructor
        
        vector<vector<int>> ans;

        if(root==nullptr){
            return ans;
        }


        bool evenFlag = true; // at 0 depth initially
        qu.push(root);

        while(!qu.empty()){
            auto x = qu.front();
            int s = qu.size();
            vector<int> v(s);

            for(int i = 0; i<s; i++){
                auto node = qu.front();
                // v.push_back(node->val);
                qu.pop();

                int index = evenFlag ? i : (s - 1 - i);
                v[index] = node->val;

                if (node->left != nullptr) {
                    qu.push(node->left);
                }
                if (node->right != nullptr) {
                    qu.push(node->right);
                }

                // if(evenFlag){
                //     if(node->left!=nullptr){ 
                //         qu.push(node->left);
                //     }

                //     if(node->right!=nullptr){ // dont use else if here as here if isnt used as a conditional but as a sanity check
                //         qu.push(node->right);
                //     }
                // }
                // else if(!evenFlag){
                    

                //     if(node->right!=nullptr){
                //         qu.push(node->right);
                //     }


                //     if(node->left!=nullptr){
                //         qu.push(node->left);
                //     }

                    
                // }
              

            }

            ans.push_back(v);
            evenFlag = !evenFlag;

        }

        return ans;
    }
};
// @lc code=end

