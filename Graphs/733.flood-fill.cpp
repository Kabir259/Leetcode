/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#define Speed ios_base::sync_with_stdio(false);
#define Up cin.tie(NULL);
#define Code cout.tie(NULL);


// Code-----------------------------------------------------------------------------------------------


// Main-----------------------------------------------------------------------------------------------

// @lc code=start
class Solution {
public:

    void bfs(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>>& vis){
        vis[sr][sc]=1;
        queue<pair<int,int>> qu;
        qu.push(make_pair(sr,sc));

        int dx[4]= {0,0,1,-1};
        int dy[4]={1,-1,0,0};
        int m = image.size();
        int n = image[0].size();

        while(!qu.empty()){
            pair<int,int> p = qu.front();
            qu.pop();
            int x = p.first;
            int y = p.second;
            for(int k = 0 ; k<4; k++){
                int nx = x+dx[k];
                int ny= y+dy[k];
                bool valid = (nx>=0 && nx<m && ny>=0 && ny<n);
                if(valid && image[x][y]==image[nx][ny] && vis[nx][ny]==0){
                    vis[nx][ny]=1;
                    qu.push(make_pair(nx,ny));
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> vis(image.size(),vector<int>(image[0].size(),0));
        bfs(image,sr,sc,color, vis);

        vector<vector<int>> result(image.size(),vector<int>(image[0].size()));

        for(int i = 0; i<image.size(); i++){
            for(int j = 0; j<image[0].size(); j++){
                if(vis[i][j]==1){
                    image[i][j]=color;
                }
            }
        }
        return image;

    }

};
// @lc code=end

