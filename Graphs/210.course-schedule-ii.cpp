/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> inDeg(numCourses,0);

        for(auto row:prerequisites){
            int a = row[0];
            int b = row[1];
            adj[b].push_back(a);
            inDeg[a]++;
        }

        queue<int> qu;

        vector<int> topo;

        for(int i =0; i<inDeg.size(); i++){
            if(inDeg[i]==0){
                qu.push(i);
            }
        }


        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            topo.push_back(node);

            for (auto x: adj[node]){
                inDeg[x]--; 
                if(inDeg[x]==0){
                    qu.push(x);
                }
            }
        }

        if(topo.size() == numCourses) {
            return topo;
        } else {
            return {};
        }
    }
};
// @lc code=end

