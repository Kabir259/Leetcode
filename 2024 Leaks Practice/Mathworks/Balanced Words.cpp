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


// Code-----------------------------------------------------------------------------------------------
class Solution {
private:
    const int MOD = 1000000007;
    const int ALPHABET_SIZE = 26;
    
    // Helper function to multiply two matrices
    vvll multiplyMatrix(vvll a, vvll b){
        ll n = a.size();
        vvll ans(n,vll(n,0));

        fl(i,0,n){
            fl(j,0,n){
                fl(k,0,n){
                    ans[i][j] = (ans[i][j]+(a[i][k]*b[k][j])%MOD)%MOD;
                }
            }
        }

        return ans;

    }
    
    // Helper function to multiply matrix with vector
    vector<long long> multiplyMatrixVector(vvll mat, vll vec){
        ll n = mat.size();
        vvll ans(n,vll(n,0));
        fl(i,0,n){
            fl(j,0,n){
                ans[i][j]= (ans[i][j]+(mat[i][j]*vec[j])%MOD)%MOD;
            }
        }
    }
    
    // Matrix power function
    vector<vector<long long>> matrixPower(vector<vector<long long>>& matrix, int power) {
        int n = matrix.size();
        
        // Base case: identity matrix
        if(power == 0) {
            vvll id(n,vll(n,0));
            fl(i,0,n){
                id[i][i] = 1;
            }
            return id;
        }

        if(power&1 == 1){
            vvll temp = matrixPower(matrix,n-1);
            return multiplyMatrix(matrix,temp);
        }
        else{
            vvll temp = matrixPower(matrix,n/2);
            return multiplyMatrix(temp,temp);
        }
    }

public:
    int countBalancedWords(int n, int d) {
        // Handle base cases
        if(n <= 0) return 0;
        if(n == 1) return ALPHABET_SIZE;
        
        vvll dist(ALPHABET_SIZE,vll(ALPHABET_SIZE,0));

        fl(i,0,ALPHABET_SIZE){
            fl(j,0,ALPHABET_SIZE){
                if(abs(i-j)<=d){
                    dist[i][j]=1;
                }
            }
        }

        // initial_alphabet_vec * dist^words-1 = finalvec. return summ(finalvec);

        vll state(ALPHABET_SIZE,1);
        vvll dn = matrixPower(dist,n-1);
        vll final = multiplyMatrixVector(dn,state);

        return accumulate(be(final),0);

    }
};


// Main-----------------------------------------------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solution solution;
    // Example tests
    cout << solution.countBalancedWords(1, 0) << endl;  // 26
    cout << solution.countBalancedWords(2, 1) << endl;  // Number of words where adjacent letters differ by at most 1
    cout << solution.countBalancedWords(3, 2) << endl;  // Number of words where adjacent letters differ by at most 2


    return 0;
}
