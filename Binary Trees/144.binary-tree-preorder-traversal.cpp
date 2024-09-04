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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        if(root==nullptr){
            return ans;
        }

        // queue<*TreeNode> qu; 
        // to get data->left->right for pre order, emphasis was laid on left being first then right
        // so we can use LIFO property of STACK to get this. LIFO will prioritise the last element 
        // while popping always. so we put right child first then the left child so in that way
        // it will always focus on left child

        stack<TreeNode*> st;

        st.push(root);

        while(!st.empty()){
            auto node = st.top();
            ans.push_back(node->val);
            st.pop();

            if(node->right!=nullptr){
                st.push(node->right);
            }

            if(node->left!=nullptr){
                st.push(node->left);
            }
        }

        return ans;
    }
    
};
// @lc code=end

