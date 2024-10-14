#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(int A, int B, vector<string> &C) {
    int n=A;
    int m=B;

    vector<vector<int>>cost(n,vector<int>(m,1e9));
    cost[0][0]=0;
    
    set<pair<int,pair<int,int>>>s; // d,x,y
    s.insert({0,{0,0}});

    vector<int>dr={0,0,-1,1};
    vector<int>dc={1,-1,0,0};

    while(!s.empty()){
        auto it=*(s.begin());

        int ctill=it.first;
        int r=it.second.first;
        int c=it.second.second;

        s.erase(s.begin());
        
        for(int i=0;i<4;i++){
            int newr=r+dr[i];
            int newc=c+dc[i];
            
            if(newr<n && newr>=0 && newc>=0 && newc<m){
                int addDistancePenalty=1;
                if((C[r][c]=='U' && newr==r-1 && newc==c) 
                || (C[r][c]=='D' && newr==r+1 && newc==c)
                ||(C[r][c]=='R' && newr==r && newc==c+1)
                ||(C[r][c]=='L' && newr==r && newc==c-1)){
                    addDistancePenalty=0; // correct symbol to move onto
                } 

                if(cost[r][c]+addDistancePenalty<cost[newr][newc]){
                    cost[newr][newc]=addDistancePenalty+cost[r][c];
                    s.insert({cost[newr][newc],{newr,newc}});

                }
            }
        }
    }
    return cost[n-1][m-1];
}