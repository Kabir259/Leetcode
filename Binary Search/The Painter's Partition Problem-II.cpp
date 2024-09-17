#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution
{
  public:
    bool pred_all_painted(int m, int arr[], int n, int k){
		int painters = 1;
		int hours = 0;
		for(int i = 0; i<n; i++){
			if(arr[i]>m){
			    return false;
			}
			hours+=arr[i];
			
			if(hours>m){
			    painters++;
			    hours = arr[i];
			}
			
			if(painters>k){
			    return false;
			}
		}
		return true;
	}
    long long minTime(int arr[], int n, int k)
    {
    	// code here
    	// return minimum time
    	long long l = *max_element(arr,arr+n); // you query static arrays for void functions like this
    	long long sum = 0;
    	for(int i = 0; i < n; i++){
    		sum+=arr[i];
    	}
    	long long r = sum;

		while(l < r){
			long long m = l +(r-l)/2;

			if(pred_all_painted(m,arr,n,k)){
				r = m;
			}
			else{
				l = m+1;
			}
		}
		
		return l;        
    }
};