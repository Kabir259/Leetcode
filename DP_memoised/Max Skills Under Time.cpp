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

int taken[1001]; // mark item when you take it

bool check(int level){
    int timetaken = 0;
    int itemtaken = 0;
    for(int i = 0; i<level; i++){ // check if the actions of the past before coming to level affect level
        if(taken[i]){
            timetaken+=t[i];
            itemtaken+=1;
        }
    }
    timetaken+=t[level];
    itemtaken+=1;

    if(itemtaken<=k && timetaken<=x){
        return true;
    }
    return false;

}

int f(int level){


    if(level == n){
        return 0;
    }

    // since there are two choices only in the move part, theres no point in using a for loop

    // dont take
    int ans = f(level+1); // pessimistic case can initialise answer 

    // take
    if(check(level)){
        taken[level]=1;
        ans = min(ans, s[level] + f(level+1)); // optimistic ans can take the relating subproblem funtion i.e. max, and, or, addition etc
        // backtracking logic
        taken[level]=0;
    }






}



// Main-----------------------------------------------------------------------------------------------
int main()
{
    Speed Up Code

    

    return 0;
}
