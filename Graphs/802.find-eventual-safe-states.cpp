/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        vector<vector<int>> revgraph(graph.size());
        vector<int> indeg(graph.size(),0);
        
        for(int i = 0; i<graph.size(); i++){
            for(int j=0; j<graph[i].size(); j++){
                int node= graph[i][j];
                revgraph[node].push_back(i);
                indeg[i]++;
            }
        }        

        queue<int> q;

        vector<int> topo;

        for(int i =0; i<indeg.size(); i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto n: revgraph[node]){
                indeg[n]--;
                if(indeg[n]==0){
                    q.push(n);
                }
            }

        }

        sort(topo.begin(), topo.end());
        return topo;
    }
};
// @lc code=end

