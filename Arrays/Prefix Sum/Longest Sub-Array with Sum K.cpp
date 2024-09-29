#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(){
        
    }

    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        map<int,int> m;
        int maxlen = 0;
        int sum = 0;
        m[0] = 1;

        for(int i = 0; i<N; i++){
            sum+=A[i];

            if(sum==K){
                maxlen = max(maxlen,i+1); // init the maxlen by the first time you encountered sum k
            }
            
            int prefixsum = sum-K; // from there on start finding residual subsets (jump to line 31)

            if(m.find(prefixsum)!=m.end()){ // if it already exists
                int len = i - m[prefixsum]; // length of the useful residual excludnig length of prefix residual
                maxlen = max(maxlen,len); // update length
            }

            m[prefixsum] = i; // store the residual sum -> idx found in a map (to line 26)
        }
        return maxlen;
    }

};