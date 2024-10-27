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








// Code-----------------------------------------------------------------------------------------------

ll numberOfInterestingPoints(str start, str end){
    ll count = isInteresting(start) ? 1: 0;
    while(start!=end){
        start = step(start);
        count+=isInteresting(start);
    }
    return count;
}

typedef unordered_set<ch> usch;

bool isInteresting(str& time){
    usch uniqueDigits;
    for(char c: time){
        if(c!=':') uniqueDigits.insert(c);
    }
    return uniqueDigits.size()<=2;
}

str step(str& time){
    ll hr = stoi(time.substr(0,2));
    ll min = stoi(time.substr(3,2));
    ll sec = stoi(time.substr(6,2));

    sec++;
    if(sec==60){
        sec=0;
        min++;

        if(min==60){
            min=0;
            hr++;

            if(hr==24){
                hr=0;
            }

        }
    }
    return formatTime(hr,min,sec);
}

str formatTime(ll hr, ll min, ll sec){
    char buffer[9];
    snprintf(buffer,sizeof(buffer),"%02d:%02d:%02d",hr,min,sec);
    return string(buffer);
}




// Main-----------------------------------------------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;
    // while(t--){
    //     solve();
    // }

    return 0;
}
