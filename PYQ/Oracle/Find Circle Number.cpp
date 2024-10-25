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

void make(int x, vll&p, vll&size){
    p[x]=x;
    size[x]=1;
}

ll find(int x, vll&p){
    if(p[x]==x) return x;
    else return p[x]=find(p[x],p); 
}

void Union(int x, int y, vll& p, vll& size){
    x = p[x]; 
    y = p[y];
    if(x!=y){
        if(size[x]<size[y]) swap(x,y);
        p[y]=x;
        size[x]+=size[y];
    }
}

int getSize(int x, vll p, vll size){
    return size[find(x,p)];
}

// https://www.fastprep.io/problems/oracle-find-circle-num
class Solution {
public:
  vll findCircleNum(vector<string> queryType, vector<int> student1, vector<int> student2) {
    set<int> unique_people;
    int s = student1.size();

    for(int i = 0; i<s; i++){
        int a = student1[i];
        int b = student2[i];
        a--;b--; // 0 idxing

        unique_people.insert(a);
        unique_people.insert(b);
    }

    int n = unique_people.size();

    vll p(n);
    vll size(n);

    for(auto it = unique_people.begin(); it!=unique_people.end(); it++){
        int x = *it;
        make(x,p,size);
    }

    vll ans;
    
    fl(i,0,n){
        int a  = student1[i];
        int b = student2[i];
        a--;b--;
        if(queryType[i]=="Friend"){
            Union(a,b,p,size);
        }
        else{// Total
            int leader1 = find(a,p);
            int leader2 = find(b,p);
            // return size of leader not child

            if(leader1!=leader2){
                int temp = getSize(leader1,p,size) + getSize(leader2,p,size);
                ans.pb(temp); 
            }
            else{
                int temp = getSize(leader1,p,size);
                ans.pb(temp); 
            }
        }
    }
    return ans;
    
  }
};
