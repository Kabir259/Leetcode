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


ll len(vll v) {return v.size();}
template <typename T>
void printvec(vector<T> v){ll n=v.size();fl(i,0,n)cout<<v[i]<<" ";cout<<"\n";}
template<typename T>
ll sumvec(vector<T> v){ll n=v.size();ll s=0;fl(i,0,n)s+=v[i];return s;}
void swap(ll &x,ll &y){ll temp = y;y = x;x = temp;}


ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
ll powa(ll a, ll b, ll m = mod){if (b == 0)return 1ll;else if (b == 1)return a;else{ll x = powa(a, b/2, m);x *= x;if (b%2){x *= a;}return x;}}


bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}


string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}


bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}


// Code-----------------------------------------------------------------------------------------------
vll solve(vll& a, vll & b, ll n){
    /*Given two arrays a and b, each containing integers, find two integers x and y for each index i such that:
   
    x + y = a[i]
    x XOR y=b[i]

    If there exists such x and y, return the value 2x+3y. Otherwise, return 0.

    Constraints:
    The elements in a and b are non-negative and may go up to 64-bit integers.
    Return the answer for each index as an array of results.*/
    

    vll ans(n);
    fl(i,0,n){
        if(a[i]<b[i]){
            ans[i]=0;
        }

        ll x = 0, y=0;
        ll j = 0;
        // find diff
        // use property => A+B == A^B + 2(A&B) == A|B + A^B
        ll diff = (a[i]-b[i])/2; // a&b

        while(j<63){

            if(b[i] & (1 << j) == 1){ // if b_j set
                if(diff & (1<<j) == 0){ // if diff_j unset, set y_j
                    y|=(1<<j);
                }
                else{ // diff_j set and y_j set = impossible
                    x=0;
                    y=0;
                    break;
                }
            }
            else{ // if b_j unset
                if(diff & (1<<j) == 1){ // diff_j set, set x_j,y_j
                    x|=(1<<j);
                    y|=(1<<j);
                }
            }

            ans[i] = 2*x+3*y;

            j++;
        }
    }
    return ans;
    

}


// Main-----------------------------------------------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        // solve();
    }

    return 0;
}
