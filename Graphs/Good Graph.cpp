#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void dfs(int u, vector<int>& A, vector<int>& vis, int c, int& ans) {
    vis[u] = c;
    int v = A[u] - 1;  // Convert to 0-based indexing
    if (vis[v] == c && v != 0) ans++;
    if (!vis[v]) dfs(v, A, vis, c, ans);
}

int Solution::solve(vector<int>& A) {
    int n = A.size();
    vector<int> vis(n, 0);
    int ans = 0, c = 1;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, A, vis, c, ans);
            c++;
        }
    }
    return ans;
}