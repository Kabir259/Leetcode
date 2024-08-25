/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */

// @lc code=start

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


// Code-----------------------------------------------------------------------------------------------


class Solution {
public:
    void dfs(int n, vector<vector<int>>& adj, 
    int source, vector<int>& vis){
        vis[source]=1;
        for(auto neigh:adj[source]){
            if(!vis[neigh]){
                dfs(n,adj,neigh,vis);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> vis(n,0);

        vector<vector<int>> adj(n); // always while declaring adj list decalre the initial no of nodes by doing adj(n)
        for(auto i:edges){
            int a = i[0];
            int b = i[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(n,adj,source,vis);

        return vis[destination];

    }
};
// @lc code=end

