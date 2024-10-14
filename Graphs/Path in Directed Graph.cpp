#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adj(A);
    for(auto edge:B){
        int a = edge[0]; a--;
        int b = edge[1]; b--;
        adj[a].push_back(b);
        //directed 
    }
    
    vector<bool> vis(A,0);
    
    queue<int> qu;
    qu.push(0);
    vis[0] = true;
    
    while(!qu.empty()){
        int x = qu.front();
        qu.pop();
        
        for(int n : adj[x]){
            if(!vis[n]){
                qu.push(n);
                vis[n]=true;
            }
        }
    }
    
    return (int)vis[A-1];
    
    
}