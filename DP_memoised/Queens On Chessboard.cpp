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



bool valid(int row, int col, vvll& grid, vll& queens){
    for(int i = 0; i<row; i++){
        int prow = i;
        int pcol = queens[i];

        if(pcol==col || abs(col-pcol)==abs(row-prow)){
            return false;
        }
    }
    return true;
}


int f(int row, vvll& grid, vll& queens){

    if(row>8){
        return 0;
    }

    if(row==8){
        return 1;
    }

    int ans = 0;

    for(int col = 0; col<8; col++){
        if(valid(row,col,grid,queens)){
            //place queen in cache during backtracking
            queens[row]=col;

            ans += f(row+1,grid,queens);
            // when you exit backtracking revert to -1
            queens[row]=-1;
        }
    }

    return ans;

}


// Main-----------------------------------------------------------------------------------------------
int main()
{
    Speed Up Code
    
    vvll grid(8,vll(8));
    vll queens(8);

    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            char x;
            cin>>x;
            if(x=='.'){
                grid[i][j]=1;
            }
            else{
                grid[i][j]=0;
                queens[j]=1;
            }
        }
    }

    cout<<f(0,grid,queens)<<'\n';
    

    return 0;
}
