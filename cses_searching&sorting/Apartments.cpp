#include <iostream>
#include <fstream>
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
void f(int n, int m , int k , vector<pair<int,int> >& size_choice, vector<int>& apartment_size){
    int house_allocated = 0;

    int i = 0, j = 0;

    while(j<m && i<n){
        int fwd = apartment_size[j];

        if(size_choice[i].ff<=fwd<=size_choice[i].ss){
            i++;
            j++;
            house_allocated++;
        }
        else{
            j++;
        } 
    }

    cout<<house_allocated;

}


// Main-----------------------------------------------------------------------------------------------
int main()
{
    Speed Up Code

    int n,m,k;
    cin>>n>>m>>k;

    vector<pair<int,int>> size_choice(n);
    vector<int> apartment_size(n);

    for(int i = 0; i<2; i++){
        for(int i = 0; i<n; i++){
            int a;
            cin>>a;
            pair<int,int> p = make_pair(a-k,a+k);
            size_choice[i] = p;
        }
        for(int i = 0; i<m; i++){
            cin>>apartment_size[i];
        }
    }

    f(n,m,k,size_choice,apartment_size); 

    return 0;
}