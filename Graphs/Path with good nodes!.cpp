#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int countGoodNodesInPath, int& validpaths, vector<bool>& vis,
vector<vector<int>>& adj, vector<int>& A, int C){

    if(countGoodNodesInPath>C || adj[node].empty()){
        return;
    }
    if(adj[node].empty()){
        if(countGoodNodesInPath<=C && A[node]){
            return;
        }
        else if(countGoodNodesInPath<C && A[node]){
            validpaths++;
        }
        else if(countGoodNodesInPath<=C && !A[node]){
            validpaths++;
        }
        else if(countGoodNodesInPath<C && !A[node]){
            return;
        }
    }
    if(A[node]){
        countGoodNodesInPath++;
    }
    vis[node]=true;
    for(auto n: adj[node]){
        if(!vis[n]){
            dfs(n,countGoodNodesInPath,validpaths,vis,adj,A,C);
        }
    }
}

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    vector<vector<int>> adj(B.size());
    vector<bool> vis(A.size(),false);
    for(auto edge: B){
        int a = edge[0];
        int b = edge[1];
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int validpaths = 0;
    dfs(0,0,validpaths,vis,adj,A,C);
    return validpaths;
}