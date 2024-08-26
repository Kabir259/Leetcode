#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(){
        
    }

    int totalFruits(vector<int> &arr) {
        int k = 2;
        int i = 0;
        int j = 0;
        int n = arr.size();
        
        map<int,int> m;
        int maxi=0;
        
        while(j<n){
            int fwd = arr[j];
            m[fwd]++;
            
            while(m.size()>k){
                int bwd= arr[i];
                m[bwd]--;
                
                if(m[bwd]==0){
                    m.erase(bwd);
                }
                
                i++;
            }
            
            maxi = max(maxi,j-i+1);
            
            j++;
        }
        
        return maxi;
    }
};