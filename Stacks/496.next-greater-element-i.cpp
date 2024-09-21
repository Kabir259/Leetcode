#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();

        stack<int> st;
        map<int,int> nextGreater;


        for(int i = n-1; i>=0; i--){;
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                nextGreater[nums2[i]]=-1;
            }
            else{
                nextGreater[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(int elt:nums1){
            ans.push_back(nextGreater[elt]);
        }

        

        return ans;
    }
};
// @lc code=end

