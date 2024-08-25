/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    int ans = -1;

    void bfs(vector<pair<pair<int, int>, int>>& start, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        queue<pair<pair<int, int>, int>> qu;
        for (auto p : start) {
            int x = p.first.first;
            int y = p.first.second;
            int d = p.second;
            vis[x][y] = 1;
            qu.push(p);
        }
        while (!qu.empty()) {
            auto p = qu.front();
            qu.pop();
            for (int k = 0; k < 4; k++) {
                int nx = p.first.first + dx[k];
                int ny = p.first.second + dy[k];
                int nd = p.second + 1;
                bool valid = (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size());
                if (valid && grid[nx][ny] == 1 && vis[nx][ny] == 0) {
                    vis[nx][ny] = 1;
                    qu.push(make_pair(make_pair(nx, ny), nd));
                    ans = max(ans, nd);
                }
            }
        }
    }

    //similar question: leetcode 542 01 matrix. multisource bfs depth maintained in 0(1) for each node

    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<pair<int, int>, int>> start;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int x = grid[i][j];
                if (x == 2) {
                    start.push_back(make_pair(make_pair(i, j), 0));
                }
            }
        }

        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size()));
        bfs(start, grid, vis);

        bool noFreshOrangeLeft = true;
        bool freshOrangeExists = false;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!vis[i][j] && grid[i][j]==1) {
                    noFreshOrangeLeft= false;
                }
                if(!freshOrangeExists && grid[i][j]==1){
                    freshOrangeExists = true;
                }
            }
        }
        
        if(freshOrangeExists){
            if(noFreshOrangeLeft){
                return ans;
            }
            if(!noFreshOrangeLeft){
                return -1;
            }
        }
        return 0;
    }
};
