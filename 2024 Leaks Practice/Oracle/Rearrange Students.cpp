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


// Code-----------------------------------------------------------------------------------------------
ll solve(vll& A, vll& B){
    int n,m,k;
    n = A.size();

    // dont use 2ptr

    mll mp;
    ll mini = INF;
    vll x;

    fl(i,0,n){
        
        mp[A[i]]++;
        mp[B[i]]--;
        mini = min(mini,A[i]);
        mini = min(mini,B[i]);
    }

    for(auto it: mp){
        ll freq = it.ss;
        if(freq&1){
            return -1;
        }
        else{
            ll elt = it.ff;
            fl(j,0,abs(freq)/2){
                x.pb(elt);
            }
        }
    }

    // cost of swapping is the minimum height
    ll ans = 0;
    m = x.size();
    fl(i,0,m/2){
        ans+=min(2*mini,x[i]);
    }

    return ans;


}


// Main-----------------------------------------------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        // solve();
    }

    return 0;
}
