#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(){
        
    }

    int numberOfSubstrings(string s) {
        int n = s.size();

        int i = 0 ;
        int j = 0;

        int count=0;

        map<char,int> m;

        while(j<n){
            char fwd = s[j];
            m[fwd]++;
            
            while(m['a']>0 && m['b']>0 && m['c']>0){
                count += (n-j);
                char bwd = s[i];
                m[bwd]--;
                i++;
            }
            // reason why count isnt here is because you need to first hit all the a b c atleast one for you to be able to begin counting.
            
            j++;
        }

        return count;
    }
};