/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
    void dfs(TreeNode* root, int targetSum, long long prefixsum, unordered_map<long long,int>& m, int &ans){
        // remember not to pass prefixsum by value(usingn &)
        // you are doing backtracking do not edit the prefix sum
        if(!root){
            return;
        }

        prefixsum+=root->val;

        long long diff = prefixsum-targetSum;

        if(m.find(diff)!=m.end()){
            ans+=m[diff];
        }
        m[prefixsum]++;

        dfs(root->left, targetSum,prefixsum, m, ans);
        dfs(root->right,targetSum,prefixsum, m, ans);

        m[prefixsum]--;

        // stack<TreeNode*> st;

        // while(root || !st.empty()){
        //     while(root){
        //         prefixsum+=root->val;
        //         int diff = prefixsum-targetSum;
        //         if(m.find(diff)!=m.end()){
        //             ans+=m[diff];
        //         }
        //         m[diff]++;

        //         st.push(root);
        //         root=root->left;
        //     }

        //     // now root is null so you need to backtrack to st.top() to save your ass
        //     // while backtracking "forget" the sums you encountered by subtracting

        //     root = st.top();
        //     int newdiff = prefixsum - root->val;
        //     m[newdiff]--;

        //     st.pop();
        //     root=root->right;

        }


    int pathSum(TreeNode* root, int targetSum) {
        /*
        Given the root of a binary tree and an integer targetSum, 
        return the number of paths where the sum of the values along the 
        path equals targetSum.

        the question wants you to find the frequency of a targetsum in a 
        contigous path similar to an array -> PREFIX SUM

        here while bbacktracking you would need to do a map[arr[j]-targetsum]-- though
        unlike arrays
        */

       unordered_map<long long,int> m;
       m[0]=1;
       long long prefixsum = 0;
       //Line 21: Char 18: runtime error: signed integer overflow: 2000000000 + 1000000000 cannot be represented in type 'int' (solution.cpp)
        // uyoull get overflow error if u use int. use ll.

       int ans = 0;
       dfs(root,targetSum, prefixsum,m,ans);

       return ans;
    }
};
// @lc code=end

