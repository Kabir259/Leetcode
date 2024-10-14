#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void bfs(int i, int j, vector<vector<char>>& A, vector<vector<bool>>& vis) {
    int m = A.size();
    int n = A[0].size();
    queue<pair<int, int>> qu;
    qu.push({i, j});
    vis[i][j] = true;
    A[i][j] = 'B';  // Mark as boundary-connected 'O' to avoid flipping later

    // 4 possible directions (up, down, left, right)
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!qu.empty()) {
        pair<int, int> p = qu.front();
        int x = p.first;
        int y = p.second;
        qu.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            // Only continue BFS if within bounds, unvisited, and still 'O'
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && A[nx][ny] == 'O') {
                qu.push({nx, ny});
                vis[nx][ny] = true;
                A[nx][ny] = 'B';  // Mark as boundary-connected
            }
        }
    }
}

void Solution::solve(vector<vector<char>>& A) {
    int m = A.size();
    if (m == 0) return;
    int n = A[0].size();

    vector<vector<bool>> vis(m, vector<bool>(n, false));

    // Step 1: Traverse boundary rows and columns to mark boundary-connected 'O's
    for (int i = 0; i < m; i++) {
        if (A[i][0] == 'O' && !vis[i][0]) {
            bfs(i, 0, A, vis);  // Left boundary
        }
        if (A[i][n-1] == 'O' && !vis[i][n-1]) {
            bfs(i, n-1, A, vis);  // Right boundary
        }
    }
    
    for (int j = 0; j < n; j++) {
        if (A[0][j] == 'O' && !vis[0][j]) {
            bfs(0, j, A, vis);  // Top boundary
        }
        if (A[m-1][j] == 'O' && !vis[m-1][j]) {
            bfs(m-1, j, A, vis);  // Bottom boundary
        }
    }

    // Step 2: Flip all unmarked 'O's to 'X', as they are surrounded
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 'O') {
                A[i][j] = 'X';  // Surrounded region, flip to 'X'
            }
        }
    }

    // Step 3: Convert 'B' (boundary-connected 'O') back to 'O'
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 'B') {
                A[i][j] = 'O';  // Restore boundary-connected 'O'
            }
        }
    }
}