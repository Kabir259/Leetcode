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
        m[0] = -1;

        for(int i = 0 ;i<N ; i++){
            sum+=A[i];
            if(m.find(sum-K)!= m.end()){
                maxlen = max(maxlen,i-m[sum-K]);

            }
            
            if(m.find(sum)==m.end()){ // this sum will later on become a sum-k for some other value
            // so we dont neeed to check the condition m.find(sum-k)!=m.end(){m[sum-k]=i;}
            // this is guaranteed. if not, then return 0 as it is. there was no way to make k out of a subarray then.
                m[sum] = i;
            }
            

        }

        
        return maxlen;
    }

};