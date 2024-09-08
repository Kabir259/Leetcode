#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string Solution::findDigitsInBinary(int A) {
    string s;
    if(A==0){
        s.push_back('0');
    }
    
    while(A>0){
        s.push_back((A%2)+'0');
        A/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}