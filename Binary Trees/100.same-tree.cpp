#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// // Definition for a binary tree node.
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

    bool isSameTreeUntil(TreeNode* p, TreeNode* q, bool& ans){
        if(p==nullptr||q==nullptr){
            if(p==nullptr && q==nullptr) {
                return true;
            }
            ans = false;
            return false; 
        }

        bool lsol = isSameTreeUntil(p->left,q->left,ans);
        bool rsol = isSameTreeUntil(p->right,q->right,ans);

        ans = ans&&(lsol&&rsol)&&(p->val==q->val);

        return lsol&&rsol&&(p->val==q->val);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = true;

        isSameTreeUntil(p,q,ans);
        
        return ans;

    }
};
// @lc code=end

