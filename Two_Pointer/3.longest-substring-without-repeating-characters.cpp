#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    

    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i =0, j=0;
        unordered_map<char,int> m;
        int maxi = 0;

        while( j<n){
            char b = s[j];
            m[b]++;

            while(m[b]>1){
                char a = s[i];
                m[a]--;
                i++;
            }
            
            maxi = max(maxi,j-i+1);
            j++;            
        }
        return maxi;
    }

};