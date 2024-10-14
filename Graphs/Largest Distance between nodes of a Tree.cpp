#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// x = current node, p = its parent, n = x's children

void farthestleaf(int x, int p, vector<vector<int>>& adj, vector<int>& fleaf, vector<int>& parent){
    parent[x] = p;
    for(auto n: adj[x]){
        if(n!=p){
            farthestleaf(n,x,adj,fleaf, parent);
            fleaf[x] = max(fleaf[x],fleaf[n]+1);
        }
    }
}

void largestPath(int x, int p, vector<vector<int>>& adj, vector<int>& fleaf, vector<int>& path) {
    pair<int,int> top2child = {-1,-1};

    for(auto n : adj[x]) {
        if(n != p) {
            largestPath(n, x, adj, fleaf, path);
            int farthestFromNeighbour = fleaf[n];
            
            if(farthestFromNeighbour > top2child.first) {
                top2child.second = top2child.first;
                top2child.first = farthestFromNeighbour;

            } else if(farthestFromNeighbour > top2child.second) {
                top2child.second = farthestFromNeighbour;
            }
        }
    }
    path[x] = top2child.first + top2child.second + 2;
}


//Solution::
int solve(vector<int> &A) {
    int N = A.size();
    vector<vector<int>> adj(N);

    int root = -1;
    for(int i = 0; i < N; i++) {
        if(A[i] == -1) {
            root = i;
        } else {
            adj[A[i]].push_back(i);
            adj[i].push_back(A[i]);
        }
    }

    vector<int> fleaf(N, 0);
    vector<int> path(N, 0);
    vector<int> parent(N, -1);
    
    farthestleaf(root, -1, adj, fleaf, parent);
    largestPath(root, -1, adj, fleaf, path);

    return *max_element(path.begin(), path.end());
}