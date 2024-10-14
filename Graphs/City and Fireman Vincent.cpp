#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#define Speed ios_base::sync_with_stdio(false);
#define Up cin.tie(NULL);
#define Code cout.tie(NULL);


using ll= long long;
using ii = int;
using lld= long double;
using ull= unsigned long long;
using str = string;
using ch = char;


const lld pi= 3.141592653589793238;
const ll INFll= LLONG_MAX;
const ii INF = INT_MAX;
const ii mod=1e9+7;


typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef pair<ii, ii> pii;
typedef vector<pii> vpii;

typedef vector<str> vs;
typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;
typedef set<ll> sll;
typedef unordered_set<ll> usll;


#define ff first
#define ss second
#define pb push_back
// #define mp make_pair
#define py cout<<"YES\n";
#define pm cout<<"-1\n";
#define pn cout<<"NO\n";
#define be(v) v.begin(),v.end()
#define eb(v) v.end(),v.begin()


// Code-----------------------------------------------------------------------------------------------
// Disjoint Set Union

void make(long long x, vector<long long>& parent, vector<long long>& size){
    parent[x]=x; size[x]=1;
}
long long find(long long x, vector<long long>& parent, vector<long long>& size){
    if(parent[x]==x) return x;
    else return find(parent[x],parent,size);
}
void Union(long long x, long long y, vector<long long>& parent, vector<long long>& size){
    x = find(x,parent,size); y = find(y,parent,size);
    if(x!=y){
        if(size[x]<size[y]) swap(x,y);
        parent[y] = x; size[x]+=size[y];
    }
}

// Main-----------------------------------------------------------------------------------------------
int main()
{
    Speed Up Code

    long long n,m;
    cin>>n;
    vector<long long> E(n+1,0);
    vector<long long> parent(n+1,0);
    vector<long long> size(n+1,0);

    for(long long i = 1; i<=n; i++){
        make(i,parent,size);

        long long risk;
        cin>>risk;
        E[i] = risk;
    }
    cin>>m;
    for(long long j = 1; j<=m; j++){
        long long a,b;
        cin>>a>>b;
        Union(a,b,parent,size);
    }
    
    // explicit path compression because doing it inside find doesnt work

    for (int i = 1; i <= n; i++) {
        parent[i] = find(i, parent, size);
    }

    map<int, multiset<long long>> component_map;
    for (int i = 1; i <= n; i++) {
        component_map[parent[i]].insert(E[i]);
    }

    long long ans = 1;

    // Calculate the minimum risk and number of ways
    for (auto &component : component_map) {
        auto &risk_set = component.second;
        long long min_risk = *risk_set.begin();  // Find the minimum risk in the component
        long long cnt = risk_set.count(min_risk);  // Count how many cities have that minimum risk
        
        // Multiply the number of ways to choose cities with minimum risk in this component
        ans = (ans * cnt) % mod;
    }

    cout << ans << endl;

    return 0;
}
