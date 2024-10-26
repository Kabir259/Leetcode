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
#include <bits/stdc++.h>
using namespace std;
struct Point
{
	double x, y;
};


double area(Point p1, Point p2, Point p3)
{
	return abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0);
}

bool isInside(Point a, Point b, Point c, Point p)
{	double A = area(a, b, c);
	double A1 = area(b, c, p);
	double A2 = area(a, c, p);
	double A3 = area(b, a, p);
	return A == A1 + A2 + A3;
}
int pointsBelong(int x1, int y1, int x2, int y2, int x3, int y3, int xp, int yp, int xq, int yq)
{
	Point a = {static_cast<double>(x1), static_cast<double>(y1)};
	Point b = {static_cast<double>(x2), static_cast<double>(y2)};
	Point c = {static_cast<double>(x3), static_cast<double>(y3)};
	Point p = {static_cast<double>(xp), static_cast<double>(yp)};
	Point q = {static_cast<double>(xq), static_cast<double>(yq)};

	double ab = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y,2));
	double bc = sqrt(pow(c.x - b.x, 2) + pow(c.y - b.y,2));
	double ac = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y,2));

	int output = 0;
	if (ab + bc > ac && bc + ac > ab && ab + ac > bc)
	{
		if (isInside(a, b, c, p) && isInside(a, b, c, q))
		{
			output = 3;
		}
		else if (isInside(a, b, c, p))
		{
			output = 1;
		}
		else if (isInside(a, b, c, q))
		{
			output = 2;
		}
		else
		{
			output = 4;
		}
	}
	return output;
}
int main() {
	int result = pointsBelong(2, 2, 7, 2, 5, 4, 4, 3, 7, 4);
	cout << result << endl;
	return 0;
}
