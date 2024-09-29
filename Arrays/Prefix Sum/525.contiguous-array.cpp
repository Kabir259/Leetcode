#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(){
        
    }

    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int maxi = 0;
        map<int,int> m;
        // map: sum -> idx
        // here sum will be calculated as if 1 -> +1, if 0 -> -1.
        // so a subarr with equal no. of 1s and 0s will give net sum = 0
        // now check the max len of all these 0 subarrs
        m[0]=-1; // 0 sum at -1 (imaginary) index

        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                sum+=-1;
            }
            if(nums[i]==1){
                sum+=1;
            }

            if(m.find(sum)!=m.end()){
                maxi=max(maxi,i-m[sum]);
            }
                // [......j-1.j.......i......]
                // prefixsum(subarr[i,j]) = prefixsum(i) - prefixsum(j-1) i.e. {[.....j-1][j......i]....}
                // given prefixsum(i) - prefixsum(j-1) = 0 acc. to how i have defined rolling rum/ prefix sum
                // therefore p(i) = p(j-1); // always separate i on lhs and j on rhs. dont put anything with j. in other questions this would look like p(i)-k=p(j-1).
                // {p(i)=:p(j-1)}-->map--->{j-1 index}
                // length = i-j+1 => i-(j-1) => by map definition=> i - m[sum]. sum is equal to p(i) as current idx in the for loop is i for which instantanous sum exists.
            if(m.find(sum)==m.end()){
                m[sum]=i;
            }
        }
        return maxi;
    }
};