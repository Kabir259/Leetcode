#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void make(int x, vector<int>& parent, vector<int>& size){
    parent[x]=x; size[x]=1;
}
int find(int x, vector<int>& parent, vector<int>& size){
    if(parent[x]==x) return x;
    else return parent[x]=find(parent[x],parent,size);
}
void Union(int x, int y, vector<int>& parent, vector<int>& size){
    x = find(x,parent,size); y = find(y,parent,size);
    if(x!=y){
        if(size[x]<size[y]) swap(x,y);
        parent[y] = x; size[x]+=size[y];
    }
}


// Solution::
int solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    int N = A.size();
    vector<int> parent(N+1), size(N+1);

    for(int i = 1; i <=N;i++){
        make(i,parent,size);
    }

    for(auto e: C){
        int a,b;
        a = A[e[0]-1];
        b = A[e[1]-1];
        Union(a,b,parent,size);
    }

    bool isPermutable = true;

    for(int i = 0; i<N; i++){
        if(A[i]==B[i]) continue;
        else if(find(A[i],parent,size)!=find(B[i],parent,size)){
            isPermutable=false;
            break;
        }
        else{
            continue;
        }
    }

    // int i = 0;

    // while(isPermutable && i<N){
    //     int component_size = 0;
    //     int p = find(B[i],parent,size);
    //     component_size++;

    //     while(component_size<size[p] && p==parent[B[i]]){
    //         i++;
    //         component_size++;
    //     }

    //     if(component_size==size[p] && p==parent[B[i]]){
    //         isPermutable = true;
    //     }
    //     else{
    //         isPermutable= false;
    //         break;
    //     }
    // }
    return (int)isPermutable;
}