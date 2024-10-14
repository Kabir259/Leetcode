#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#define Speed ios_base::sync_with_stdio(false);
#define Up cin.tie(NULL);
#define Code cout.tie(NULL);


// Code-----------------------------------------------------------------------------------------------
// Disjoint Set Union

void make(long long x, vector<long long>& parent, vector<long long>& size, multiset<int>& sizes){
    parent[x]=x; size[x]=1; sizes.insert(1);
}
long long find(long long x, vector<long long>& parent){
    if(parent[x]==x) return x;
    else return parent[x]= find(parent[x],parent);
}
void merge(long long x, long long y, vector<long long>& parent, vector<long long>& size, multiset<int>& sizes){
    sizes.erase(sizes.find(size[x]));
    sizes.erase(sizes.find(size[y]));
    sizes.insert(size[x]+size[y]);
}
void Union(long long x, long long y, vector<long long>& parent, vector<long long>& size, multiset<int>& sizes){
    x = find(x,parent); y = find(y,parent);
    if(x!=y){
        if(size[x]<size[y]) swap(x,y);
        parent[y] = x; 
        merge(x,y,parent,size,sizes); 
        size[x]+=size[y]; 
    }
}


// Main-----------------------------------------------------------------------------------------------
int main()
{
    Speed Up Code

    long long n,m;
    cin>>n;
    vector<long long> parent(n+1,0);
    vector<long long> size(n+1,0);
    multiset<int> sizes;

    for(long long i = 1; i<=n; i++){
        make(i,parent,size,sizes);
    }

    cin>>m;
    for (long long j = 0; j < m; j++) {
        long long a,b;
        cin>>a>>b;
        long long rootA = find(a, parent); // Find root of A
        long long rootB = find(b, parent); // Find root of B

        if (rootA != rootB) {
            Union(a, b, parent, size, sizes); // Only union if they are in different components
        }

        if (sizes.size() == 1) {
            cout << 0 << '\n'; // Only one group
        } else {
            int mn = *(sizes.begin());
            int mx = *(--sizes.end());
            cout << mx - mn << '\n'; 
        }
    }
    // here implicit path compression inside find function works??? but why??

    // // explicit path compression because doing it inside find doesnt work
    // for (int i = 1; i <= n; i++) {
    //     parent[i] = find(i, parent, size);
    // }

    return 0;
}
