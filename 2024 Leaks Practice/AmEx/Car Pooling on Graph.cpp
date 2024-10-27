#include <iostream>
#include <bits/stdc++.h>
using namespace std;


using ll= long long;
using lld= long double;
using ull= unsigned long long;
using str = string;
using ch = char;


const lld pi= 3.141592653589793238;
const ll INF= LLONG_MAX;
const ll mod=1e9+7;


typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;


typedef vector<str> vs;
typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;
typedef set<ll> sll;
typedef unordered_set<ll> usll;


#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fl(i,m,n) for(ll i=m;i<n;i++)
#define rfl(i,m,n) for(ll i=m;i>=n;i--)
#define py cout<<"YES\n";
#define pm cout<<"-1\n";
#define pn cout<<"NO\n";
#define be(v) v.begin(),v.end()
#define eb(v) v.end(),v.begin()


int dfs(ll node, ll p , vvll& adj, ll&fuel){
    ll people =1;
    for(ll n : adj[node]){
        if(n!=p){
            ll subtree_people = dfs(n,node,adj,fuel);
            people+=subtree_people;
            fuel+=ceil(subtree_people/5.00);
        }
    }
    return people;
}

int solution(vll A, vll B, ll N){
    vvll adj(N+1);
    fl(i,0,N){
        adj[A[i]].pb(B[i]);
        adj[B[i]].pb(A[i]);
    }
    ll fuel  = 0;
    dfs(0,-1,adj,fuel);
    return fuel;
}







// Testing the solution with an example
int main() {
    vector<ll> A = {0, 1, 1}; // Example edges
    vector<ll> B = {1, 2, 3}; // Example edges
    ll N = 3;

    cout << "Minimum fuel consumption: " << solution(A, B, N) << endl; // Expected output

    return 0;
}
