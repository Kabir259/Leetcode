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
const ii INFii = INT_MAX;
const ll modll=1e9+7;
const ii modii=1e9+7;


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
#define mp make_pair
#define py cout<<"YES\n";
#define pm cout<<"-1\n";
#define pn cout<<"NO\n";
#define be(v) v.begin(),v.end()
#define eb(v) v.end(),v.begin()


// Code-----------------------------------------------------------------------------------------------
int n;
int t[1001];
int s[1001];
int x; // time contraint
int k; // items you can pick contraint

int dp[101][101][101];

int f(int level, int timetaken, int itemtaken){
    // pruning
    //base case
    if(level==n){
        return 0;
    }


    //cache check

    if(dp[level][timetaken][itemtaken]!= -1){
        return dp[level][timetaken][itemtaken];
    }



    // compute / transition

    int ans = f(level+1,timetaken,itemtaken);

    if(timetaken+t[level]<=x && itemtaken+1<=k){
        ans = min(ans,s[level]+f(level+1,timetaken+t[level],itemtaken+1));
    }


    //save and return

    return dp[level][timetaken][itemtaken] = ans;
    





}



// Main-----------------------------------------------------------------------------------------------
int main()
{
    Speed Up Code

    

    return 0;
}
