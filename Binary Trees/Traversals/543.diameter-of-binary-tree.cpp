#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:

    int diameter = 0;


    int diameterOfBinaryTree(TreeNode* root) {
        int h = height(root);

        return diameter;
    }

    // update global diameter WHILE caluclating height in O(1) inside its function that returns int height

    int height(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        
        int lsol = height(root->left);
        int rsol = height(root->right);

        diameter=max(diameter,lsol+rsol);



        return 1+max(lsol,rsol);
        


    }
};
// @lc code=end

