/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0;  i<flights.size(); i++){
            int a  = flights[i][0];
            int b = flights[i][1];
            int d = flights[i][2];
            adj[a].push_back({b,d}); // from to dist
        }

        queue<pair<int,pair<int,int>>> qu;
        // to find a rute within k stops is more important than finding a rout with minimum cost
        // we use set/pq when we need instant sorting to get min dist first while popping from set/pq;
        // but here the priority is more twds completing the flight within k stips rather than global cost minima
        // and as bfs works, stops will monotonically increase by 1 always , we can use queue

        qu.push({0,{src,0}}); // k,src,d

        vector<int> dis(n,1e9);
        dis[src]=0;

        while(!qu.empty()){
            auto x = qu.front();
            int stops = x.first;
            int node = x.second.first;
            int distUntilNow = x.second.second;
            qu.pop();

            if(stops>k){
                continue;
            }

            for(auto nbr: adj[node]){
                int adjNode = nbr.first;
                int edgeW = nbr.second;

                int newDist = distUntilNow+edgeW;

                if(newDist<dis[adjNode] && stops<=k){
                    dis[adjNode] = newDist;
                    qu.push({stops+1,{adjNode,dis[adjNode]}});
                }
                
            }
        }

        if (dis[dst]==1e9){
            return -1;
        }
        return dis[dst];

    }
};
// @lc code=end

