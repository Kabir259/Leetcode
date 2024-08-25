/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Speed
#define Speed ios_base::sync_with_stdio(false);
#define Up cin.tie(NULL);
#define Code cout.tie(NULL);


// Aliases
using ll= long long;
using ii= int;
using lld= long double;
using ull= unsigned long long;
using str = string;
using ch = char;


// Constants
const lld pi= 3.141592653589793238;
const ll INF= 1e9;
const ll mod=1e9+7;


// TypeDEf
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;

typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;
typedef set<ll> sll;
typedef unordered_set<ll> usll;

typedef vector<str> vs;
typedef vector<vs> vvs;


// Macros
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


class Solution {
public:

    void dfs(int i, vector<vector<int>>& isConnected, 
        vector<int>& vis){
            vis[i]=1;
            for(int n=0; n<isConnected[i].size(); n++){
                if(!vis[n] && isConnected[i][n]){
                    dfs(n,isConnected, vis);// dont return anything in void functions
                }
            }
        }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int cc = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                cc++;
            }
        }
        return cc;
    }
};
// @lc code=end

