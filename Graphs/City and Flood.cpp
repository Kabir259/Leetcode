#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#define Speed ios_base::sync_with_stdio(false);
#define Up cin.tie(NULL);
#define Code cout.tie(NULL);




// Code-----------------------------------------------------------------------------------------------
void make(int x, vector<int>& parent, vector<int>& size){
    parent[x] = x;
    size[x]=1;
}

int find(int x, vector<int>& parent, vector<int>& size){
    if(parent[x]==x){
        return x;
    }
    else{
        return parent[x] = find(parent[x],parent,size);
    }
}

void Union(int x, int y, vector<int>& parent, vector<int>& size){
    x = find(x,parent,size);
    y = find(y,parent,size);

    if(x!=y){
        if(size[x]<size[y]){
            swap(x,y);
        }
        parent[y]=x;
        size[x]+=size[y];
    }
}




void f(){

}


// Main-----------------------------------------------------------------------------------------------
int main()
{
    Speed Up Code

    int n, m;
    cin>>n;
    cin>>m;

    vector<int> parent(n);
    vector<int> size(n);

    for(int i = 1; i<=n; i++){
        make(i,parent,size);
    }
    while(m--){
        int x,y;
        cin>>x>>y;
        Union(x,y,parent,size);
    }

    int cc = 0;

    for(int i = 1; i<=n; i++){
        if(parent[i]==i){
            cc++;
        }
    }

    cout<<cc;
    

    return 0;
}
