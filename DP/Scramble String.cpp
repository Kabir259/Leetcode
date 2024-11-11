#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define fl(i,m,n) for(int i = m; i<n;i++)
#define rfl(i,m,n) for(int i = m; i>=n;i--)

// Solution::
int isScramble(const string A, const string B) {
    if(A==B) return 1;
    if(A.size()!=B.size()) return 0;
    
    int n = A.size();

    bool result = false;

    fl(i,1,n){
        bool notSwapped = isScramble(A.substr(0,i),B.substr(0,i)) 
                        && isScramble(A.substr(i,n-i),B.substr(i,n-i));

        bool swapped = isScramble(A.substr(0,i),B.substr(i,n-i)) 
                        && isScramble(A.substr(i,n-i),B.substr(0,i));

        if(swapped == true || notSwapped==true){
            result = true;
            break;
        }
    }
    return result;
}
