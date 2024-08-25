#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& vis){
        int n = board.size();
        int m = board[0].size();

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        queue<pair<int,int>> qu;
        vis[i][j] = true;
        qu.push({i, j});

        while(!qu.empty()){
            auto p = qu.front();
            qu.pop();
            int x = p.first;
            int y = p.second;

            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && board[nx][ny] == 'O'){
                    qu.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0) return;
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Perform BFS for 'O's on the edges
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O' && !vis[i][0]) bfs(i, 0, board, vis);
            if(board[i][m-1] == 'O' && !vis[i][m-1]) bfs(i, m-1, board, vis);
        }

        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O' && !vis[0][j]) bfs(0, j, board, vis);
            if(board[n-1][j] == 'O' && !vis[n-1][j]) bfs(n-1, j, board, vis);
        }

        // Capture all surrounded regions
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
    
};
