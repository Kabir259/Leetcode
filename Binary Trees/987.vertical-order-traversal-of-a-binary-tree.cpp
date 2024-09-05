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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        if(root==nullptr){
            return ans;
        }

        // int a = 1e9;
        // int b = -1e9;

        queue<pair<TreeNode*,pair<int,int>>> qu;
        map<int, vector<pair<int, int>>> m; // x -> [(y, value)]

        qu.push({root,{0,0}});

        while(!qu.empty()){

            int n = qu.size();            
            // while doing bfs and maintianing queue, always do while(n--) to count for all queue elements

            while(n--){
                auto [node, coords] = qu.front();
                qu.pop();

                int x = coords.first;
                int y = coords.second;

                // a = min(a,x);
                // b = max(b,x);


                

                m[x].push_back({y, node->val});

                if(node->left != nullptr) {
                    qu.push({node->left, {x-1, y+1}});
                }

                if(node->right != nullptr) {
                    qu.push({node->right, {x+1, y+1}});
                }

            }

            
        }

        // for(int i = a; i<=b; i++){ // dont do <b dont forget the =
        //     sort(m[i].begin(),m[i].end());
        //     ans.push_back(m[i]);
        // } // 

        // returns wrong ans

        for(auto& [xcoord, values] : m) {
            sort(values.begin(), values.end(), 
                [](const pair<int, int>& a, const pair<int, int>& b) {
                    return a.first < b.first || (a.first == b.first && a.second < b.second);
                }
            );

            vector<int> v;
            for(auto& [y, value] : values) {
                v.push_back(value);
            }
            ans.push_back(v);
        }

        return ans;

    }
};
// @lc code=end

