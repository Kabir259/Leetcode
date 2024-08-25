#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#define Speed ios_base::sync_with_stdio(false);
#define Up cin.tie(NULL);
#define Code cout.tie(NULL);


using ll= long long;
using lld= long double;
using ull= unsigned long long;
using str = string;
using ch = char;


const lld pi= 3.141592653589793238;
const ll INF= 1e9;
const ll mod=1e9+7;


typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
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
#define fl(i,m,n) for(int i=m;i<n;i++)
#define rfl(i,m,n) for(int i=m;i>=n;i--)

// Code-----------------------------------------------------------------------------------------------


// Main-----------------------------------------------------------------------------------------------
class Solution {
public:
    bool doesAliceWin(string s) {
        int noOfVowels = 0;

        map<char,int> m = {{'a',0},{'e',0},{'i',0},{'o',0},{'u',0}};

        fl(i,0,s.size()){
            if(m.count(s[i])){
                noOfVowels++;
            }
        }

        if(noOfVowels==0){
            return false;
        }
        return true;



    }
};
