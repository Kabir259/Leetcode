#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void precomputeSumSubtree(int root,int par, vector<int> &A, vector<vector<int>>& adj,
vector<int>& parent,vector<int>& subtreeSum){
    subtreeSum[root] += A[root];
    parent[root] = par;
    for(auto n:adj[root]){
        if(n!=par){
            precomputeSumSubtree(n,root,A,adj,parent,subtreeSum);
            subtreeSum[root]+=subtreeSum[n];
        }
    }
}
// Solution::
int deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    int sum = accumulate(A.begin(),A.end(),0);

    int root =0 ;
    vector<vector<int>> adj(A.size());
    vector<int> parent(A.size(),-1);
    vector<int> subtreeSum(A.size(),0);

    for(auto e: B){
        int a = e[0];
        int b = e[1];
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    long long ans = 0;
    precomputeSumSubtree(root,-1,A,adj,parent,subtreeSum);


    for(int i = 1; i<=A.size()-1; i++){
        int sum1 = subtreeSum[i];
        int sum2 = subtreeSum[0]-subtreeSum[i];
        ans = max(ans, 1LL*sum1*sum2);
    }
    long long mod = 1e9+7;
    return (int)(ans%mod);




}