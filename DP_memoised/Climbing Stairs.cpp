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

bool valid(int choice, int n){
    return choice <= n;
}

int f(int level, int m, int n, vector<int>& dp) {
    // pruning
    if(level > n) {
        return 0;
    }

    // base
    // here, base is when you are on the last step
    if(level == n) {
        return 1;
    }

    if(dp[level] != -1) return dp[level];

    // for all choices
    // here choice is to move on steps
    int ans = 1e9;
    for(int i = 1; i <= m; i++) { // can jump max m steps
        int choice = level + i;
        if(valid(choice, n)) {
            // move
            int ways = 1+ f(choice,m,n,dp);
            ans = min(ans,ways);
        }
    }

    return dp[level] = ans;
}

// Main-----------------------------------------------------------------------------------------------
int main()
{
    Speed Up Code

    int t;
    cin >> t;

    while(t--) {
        int m, n;
        cin >> n >> m;

        vector<int> dp(n + 1, -1);
        cout << f(1, m, n, dp) << '\n';
    }

    return 0;
}
