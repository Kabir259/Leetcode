#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int p, vector<vector<int>>& adj, vector<int>& parent, 
vector<int>& color, bool& isBipartite){
    parent[x] = p;
    if(p==-1){
        color[x] = 0;
    }
    else{
        color[x] = !color[p];
    }
    for(auto n: adj[x]){
        if(n!=p && color[n]==-1){ // unvisited
            dfs(n,x,adj,parent,color,isBipartite);
        }
        else if(n!=p && color[n]==color[x]){
            isBipartite = false;
            // break;
            return;
        }
    }
}
// Solution::

int solve(int A, vector<vector<int> > &B) {
    int N = A;
    vector<vector<int>> adj(N);
    vector<int> parent(N,-1);
    vector<int> color(N,-1);

    for(auto e: B){
        int a = e[0];
        int b = e[1];
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool isBipartite = true;
    for(int i = 0 ; i<N; i++){
        if(color[i]==-1){
            dfs(i,-1,adj,parent,color,isBipartite);
            if(isBipartite==false){
                break;
            }
        }
    }
    return isBipartite;

}
