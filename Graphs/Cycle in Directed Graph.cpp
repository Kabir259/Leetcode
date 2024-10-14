#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool dfs(int i, vector<vector<int>>& adj,vector<int>& vis , vector<int>& pathvis ){
    pathvis[i]=1;
    vis[i]=1;
    for(auto n : adj[i]){
        if(!vis[n]){
            bool recursion = dfs(n,adj,vis,pathvis);
            if(recursion ==true) return true; // the n will cut its own path pathvis in the future        
        }
        else if(pathvis[n]){
            //pakda gaya lmao n is cutting its own parents' path formed
            return true;
        }
    }
    pathvis[i]=0;
    return false;
}
// Solution::

int solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adj(A);
    for(auto e:B){
        int a = e[0];
        int b = e[1];
        a--; b--;

        adj[a].push_back(b);
        // adj[b].push_back(a);
    }

    vector<int> vis(A,0);
    vector<int> pathvis(A,0);

    for(int i = 0; i<A; i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,pathvis)==true){
                return true;
            }
        }
    }
    return false;

}