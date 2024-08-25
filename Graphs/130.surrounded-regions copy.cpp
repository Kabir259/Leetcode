/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:

    void bfs(vector<vector<char>>& board, vector<vector<bool>>& vis){
        int n = board.size();
        int m = board[0].size();

        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};

        queue<pair<int,int>> qu;
        vis[0][0]=true;
        qu.push({0,0});
        
        while(!qu.empty()){
            auto p = qu.front();
            qu.pop();
            int x = p.first;
            int y = p.second;

            for(int k = 0; k<4; k++){
                int nx = x+dx[k];
                int ny = y + dy[k];
                bool valid = (nx>=0 && nx<board.size() && ny>=0 && ny<board[0].size());
                if(valid && !vis[nx][ny] && board[x][y]==board[nx][ny]){
                    qu.push({nx,ny});
                    vis[nx][ny]=true;
                }
            }
        }
   
        
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        if(n>2 && m>2){


            // cropping is redundant approach here
            // here you just have to ignore the Os present on edges and any component connected to them
             

            vector<vector<bool>> vis(n-2,vector<bool>(m-2,false));
            vector<vector<char>> cropped(n-2,vector<char>(m-2,false));


            for (int i = 0; i<cropped.size();i++){
                for(int j=0; j<cropped[0].size(); j++){
                    if(!vis[i][j]){
                        bfs(cropped,vis);
                    }
                }
            }

            vector<bool> v(cropped[0].size(), false);

            vis.insert(vis.begin(), v.begin(), v.end());
            vis.insert(vis.end(), v.begin(), v.end());

            for(auto row : vis){
                row.insert(row.begin(), 1, false);
                row.insert(row.end(),1,false);
            } // make cropped into og dims by adding 2 rows and cols at start and end



            for (int i = 0; i<n;i++){
                for(int j=0; j<m; j++){
                    if(vis[i-1][j-1]){
                        board[i][j]='X';
                    }
                }
            }


        }
    }
};
// @lc code=end

