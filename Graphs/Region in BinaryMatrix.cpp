#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// Helper function for DFS traversal to explore the region
void dfs(int i, int j, vector<vector<int>> &A, vector<vector<int>> &vis, int &size) {
    int N = A.size();
    int M = A[0].size();

    // Directions for moving in 8 directions (horizontal, vertical, diagonal)
    int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

    // Mark the current cell as visited and increase the region size
    vis[i][j] = 1;
    size++;

    // Explore all 8 possible directions
    for (int d = 0; d < 8; d++) {
        int ni = i + dx[d];
        int nj = j + dy[d];

        // Check if the new position is within bounds, filled (1), and not visited
        if (ni >= 0 && ni < N && nj >= 0 && nj < M && A[ni][nj] == 1 && !vis[ni][nj]) {
            dfs(ni, nj, A, vis, size);  // Recursive call to explore the region
        }
    }
}

// Function to find the largest region in the binary matrix
int largestRegion(vector<vector<int>> &A) {
    int N = A.size();
    int M = A[0].size();
    vector<vector<int>> vis(N, vector<int>(M, 0));  // Visited matrix to track explored cells
    int maxRegionSize = 0;  // Variable to store the size of the largest region

    // Traverse each cell in the matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == 1 && !vis[i][j]) {  // Start DFS if a filled, unvisited cell is found
                int regionSize = 0;
                dfs(i, j, A, vis, regionSize);  // Call DFS to explore the region
                maxRegionSize = max(maxRegionSize, regionSize);  // Update the largest region size
            }
        }
    }

    return maxRegionSize;  // Return the size of the largest region
}

int Solution::solve(vector<vector<int> > &A) {
    return largestRegion(A);
}