#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(){
        
    }

    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int n = s.size();

        map<char,int> m;
        int maxi = 0;

        int maxfreq = 0;

        while(j<n){
            char fwd = s[j];
            /*
            in this question, its different from fruits into baskets on gfg in the following ways:

            in gfg: you can have [1,1,1,1,2,2,1,1,2]
            but here you can have [a,a,a,a,b,a,a,b,b,c] the addition of c is allowed as we can 
            replace c with a. we have a budget of k replacements 
            AND you will replace only those that are NOT MAJORITY OF THE FREQUENCY
            like: [a,a,b,c,a,a], k =2
            right: [a,a,a,a,a,a]
            wrong: [b,b,b,c,a,a]
            hence you must see at all time who becomes the majority when m[fwd]++ operation is done 
            and take the max m[fwd] at that time frame.

            whereas in the above gfg question the loop breaks as soon as a third variety is encountered

            */
            m[fwd]++;
            maxfreq = max(maxfreq, m[fwd]);

            while((j-i+1) - maxfreq>k){
                char bwd = s[i];
                m[bwd]--;

                if(m[bwd]==0){
                    m.erase(bwd);
                }

                i++;
            }

            maxi = max(maxi, j-i+1);


            j++;
        }

        return maxi;

    }

};