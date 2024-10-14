#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs(int i, int j, vector<vector<int>>& A, vector<vector<bool>>& vis) {
    int m = A.size();
    int n = A[0].size();
    queue<pair<int, int>> qu;
    qu.push({i, j});
    vis[i][j] = true;

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
            bool valid = nx >= 0 && nx < m && ny >= 0 && ny < n && A[nx][ny] >= A[x][y];

            if (valid && !vis[nx][ny]) {
                qu.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
}

int Solution::solve(vector<vector<int>>& A) {
    int m = A.size();
    int n = A[0].size();
    
        // Edge case: If matrix is empty or has 0 rows/columns
    if (m == 0 || n == 0) return 0;
    
    
    vector<vector<bool>> blueReachable(m, vector<bool>(n, false));
    vector<vector<bool>> redReachable(m, vector<bool>(n, false));




    // BFS for Blue lake (left and top edges)
    for (int i = 0; i < m; i++) {
        if (!blueReachable[i][0]) bfs(i, 0, A, blueReachable);       // Left edge
    }
    for (int j = 0; j < n; j++) {
        if (!blueReachable[0][j]) bfs(0, j, A, blueReachable);       // Top edge
    }

    // BFS for Red lake (right and bottom edges)
    for (int i = 0; i < m; i++) {
        if (!redReachable[i][n - 1]) bfs(i, n - 1, A, redReachable); // Right edge
    }
    for (int j = 0; j < n; j++) {
        if (!redReachable[m - 1][j]) bfs(m - 1, j, A, redReachable); // Bottom edge
    }


    // Count cells that can reach both Blue and Red lakes
    int cells = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (blueReachable[i][j] && redReachable[i][j]) {
                cells++;
            }
        }
    }

    return cells;
}