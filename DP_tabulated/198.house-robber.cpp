/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start

// Kabir Kumar | 2021EE30741 | IIT Delhi

#include <iostream>
#include <bits/stdc++.h>
// #include <sys/resource.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace chrono;
// using namespace __gnu_pbds;


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
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<pll> vpll;
typedef vector<str> vs;
typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;
typedef set<ll> sll;
typedef unordered_set<ll> usll;


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



class Solution {
public:
    int rob(vector<int>& nums) {
        ii n = nums.size();
        vii dp(n+1);
        // state = max profit from house i from nth house:
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        dp[n-1]=nums[n-1];
        dp[n-2]=n>1?max(nums[n-1],nums[n-2]):0;
        if(n>2){
            rfl(i,n-3,0){
                dp[i]=max(dp[i+1],dp[i+2]+nums[i]);
            }
        }
        return dp[0];


    }
};
// @lc code=end

