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
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }

        stack<TreeNode *> st1;
        stack<TreeNode *> st2;

        // Unlike preorder or inorder, a single stack won't work for postorder traversal
        // because in postorder, we need to process the children nodes before the root.
        // We use two stacks:
        // - The first stack (st1) is used to simulate the reverse of preorder traversal (root-right-left).
        // - The second stack (st2) will then reverse this to get the correct postorder sequence (left-right-root).

        st1.push(root);

        while (!st1.empty()) {
            auto node = st1.top();
            st1.pop();
            st2.push(node);

            // Push left child first so that right child is processed first in postorder
            if (node->left != nullptr) {
                st1.push(node->left);
            }

            // Push right child second so that left child is processed later in postorder
            if (node->right != nullptr) {
                st1.push(node->right);
            }
        }

        // Transfer nodes from the second stack to the result vector
        while (!st2.empty()) {
            auto node = st2.top();
            st2.pop();
            ans.push_back(node->val);
        }

        return ans;
    }
};
// @lc code=end
