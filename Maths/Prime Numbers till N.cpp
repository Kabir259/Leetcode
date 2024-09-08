#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> Solution::sieve(int A) {
    vector<int> prime(A+1,1);
    prime[0]=prime[1]=0;
    
    for(int i= 2; i<=(A); i++){
        if(i<sqrt(A) && prime[i]==1){
            for(int j = i*i; j<=A; j+=i){
                prime[j]=0;
            }
        }
    }
    
    vector<int> ans;
    for(int i = 0; i<A+1; i++){
        if(prime[i]) ans.push_back(i);
        
    }
    return ans;

}