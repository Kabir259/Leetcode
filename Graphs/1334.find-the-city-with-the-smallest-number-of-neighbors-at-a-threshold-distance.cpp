/*
 * @lc app=leetcode id=1334 lang=cpp
 *
 * [1334] Find the City With the Smallest Number of Neighbors at a Threshold Distance
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n,vector<int>(n,1e9));

        for(auto edge:edges){
            int u,v,w;
            u = edge[0];v=edge[1];w=edge[2];
            dis[u][v]=w;
            dis[v][u]=w;
        }

        for(int i = 0 ; i<n; i++){
            dis[i][i]=0;
        }

        for(int k =0; k<n;k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(dis[i][k]==1e9 || dis[k][j] == 1e9){
                        continue;
                    }
                    dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
                }
            }
        }

        vector<int> counter(n,0);
        int maxx = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0 ; j<n; j++){
                if(dis[i][j]<=distanceThreshold){
                        counter[i]++;
                        maxx = max(maxx,counter[i]);
                }
            }
        }

        int finalcity;
        int temp = n;

        for(int i=0; i<n; i++){
            int minn;
            if(counter[i]<=temp){
                temp = counter[i];
                finalcity=i;
            }
        }

        return finalcity;

    }
};
// @lc code=end

