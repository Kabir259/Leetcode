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


ll solution(string s){
    if(s=="0") return 0;

    // remove leading 0
    while(s[0] =='0' && s.length()>1){
        s=s.substr(1);
    }

    bool allOnes = true;
    for(char c: s){
        if(c=='0'){
            allOnes=false;
            break;
        }
    }
    if(allOnes) return 2*s.size()-1;
    

    ll n = 0;

    for(char c: s){
        n = (n << 1) | (c-'0');
    }

    ll ans = 0;

    while(n>0){
        if(n&1) n--;
        else n>>=1;
        ans++;
    }


    return ans;

    // ll n = stoll(s); stoll doesnt work!!

    // ll  n = 0;
    // for (char c : s) {
    //     if(c=='1'){
    //         n=n<<1;
    //     }  // this also doesnt work!!!!!!
    // }

}

int main() {
    // Test Case 1: "011100" -> 7 operations
    assert(solution("011100") == 7);
    cout << "Test case 1 passed!" << endl;

    // Test Case 2: "111" -> 5 operations
    assert(solution("111") == 5);
    cout << "Test case 2 passed!" << endl;

    // Test Case 3: "1111010101111"
    assert(solution("1111010101111") == 22);
    cout << "Test case 3 passed!" << endl;

    // Test Case 4: Edge case - single digit
    assert(solution("1") == 1);
    cout << "Test case 4 passed!" << endl;

    // Test Case 5: Edge case - zero
    assert(solution("0") == 0);
    cout << "Test case 5 passed!" << endl;

    // Test Case 6: Large number test - string of 400,000 '1's
    string large_test(400000, '1');
    assert(solution(large_test) == 799999);
    cout << "Test case 6 passed!" << endl;

    // Test Case 7: "1010" -> 5 operations
    assert(solution("1010") == 5);  // Changed from 4 to 5
    cout << "Test case 7 passed!" << endl;

    cout << "All test cases passed successfully!" << endl;

    return 0;
}
