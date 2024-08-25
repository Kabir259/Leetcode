#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int i , int j, vector<vector<int>>& grid, 
    vector<vector<bool>>& vis){
        int n = grid.size();
        int m = grid[0].size();

        vis[i][j]=true;
        int dx[4] = {0,0,1,-1};
        int dy[4]= {1,-1,0,0};
        for(int k = 0; k<4; k++){
            int ni = i+dx[k];
            int nj = j+dy[k];
            bool valid = ni>=0 && ni<n && nj>=0 && nj<m;
            if(valid && grid[i][j]==grid[ni][nj] && !vis[ni][nj]){
                dfs(ni,nj,grid,vis);
            }
        }
    } // gives stack overflow

    void bfs(int i , int j, vector<vector<int>>& grid, 
    vector<vector<bool>>& vis){
        int n = grid.size();
        int m = grid[0].size();

        vis[i][j]=true;
        int dx[4] = {0,0,1,-1};
        int dy[4]= {1,-1,0,0};
        queue<pair<int,int>> qu;
        qu.push({i,j});

        while(!qu.empty()){
            pair<int,int> p = qu.front();
            int x = p.first;
            int y = p.second;
            qu.pop();


            for(int k = 0; k<4; k++){
                int ni = x+dx[k];
                int nj = y+dy[k];
                bool valid = ni>=0 && ni<n && nj>=0 && nj<m;
                if(valid && grid[x][y]==grid[ni][nj] && !vis[ni][nj]){
                    qu.push({ni,nj});
                    vis[ni][nj]=true;
                }
            }
        }
    }

    void dfs2(int i , int j, vector<vector<int>>& grid, 
    vector<vector<bool>>& vis){
        int n = grid.size();
        int m = grid[0].size();

        vis[i][j]=true;
        int dx[4] = {0,0,1,-1};
        int dy[4]= {1,-1,0,0};
        stack<pair<int,int>> st;
        st.push({i,j});

        while(!st.empty()){
            pair<int,int> p = st.top();
            int x = p.first;
            int y = p.second;
            st.pop();


            for(int k = 0; k<4; k++){
                int ni = x+dx[k];
                int nj = y+dy[k];
                bool valid = ni>=0 && ni<n && nj>=0 && nj<m;
                if(valid && grid[x][y]==grid[ni][nj] && !vis[ni][nj]){
                    st.push({ni,nj});
                    vis[ni][nj]=true;
                }
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for(int i = 0; i< n; i++){
            for(int  j =0; j<m; j++){
                if((i==0 || i==n-1) && grid[i][j]==1){
                    dfs2(i,j,grid,vis);
                }
                if((j==0 || j==m-1) && grid[i][j]==1){
                    dfs2(i,j,grid,vis);
                }
            }
        }
        int count = 0;
        for(int i = 0; i< n; i++){
            for(int  j =0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;


    }
};

