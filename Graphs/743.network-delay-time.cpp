/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int src = --k; 
        //CONVERT 1 based idxing to ) based idxing by --k NOT ++k

        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i<times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            u--;v--;

            adj[u].push_back({w,v});
        }

        vector<int> dis(n,1e9);

        set<pair<int,int>> st;
        st.insert({0,src});
        dis[src]=0;

        while(!st.empty()){
            auto it = *(st.begin());
            int disUntilNow = it.first;
            int node = it.second;

            st.erase(it);

            for(auto n: adj[node]){
                int edgW = n.first;
                int adjNode = n.second;

                int nd = disUntilNow + edgW;

                if(nd<dis[adjNode]){
                    if(dis[adjNode]!=1e9){
                        st.erase({dis[adjNode],adjNode});
                    }

                    dis[adjNode]=nd;
                    st.insert({dis[adjNode],adjNode});
                }
            }
        }

        int ans = *max_element(dis.begin(), dis.end());
        return (ans == 1e9) ? -1 : ans;


    }
};
// @lc code=end

