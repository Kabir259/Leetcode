#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binary_search_on_house(vector<int>& v, int myu){
        int l = 0;
        int r = v.size()-1;

        while(l<r){
            int m = l + (r-l)/2;

            if(myu<=v[m]){
                r = m;
            }
            else{
                l = m+1;
            }
        }
        return l;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v(nums1.begin(),nums1.end());
        for(auto x: nums2){
            v.push_back(x);
        }

        // [increasing1 | increasing 2] now find in which house the median lies

        int sup = *max_element(v.begin(),v.end());
        int inf = *min_element(v.begin(),v.end());

        int myu = sup + (sup-inf)/2;

        // true-> lies with nums1

        bool house1 = nums1[nums1.size()-1]>=myu;

        if(house1){
            int med = binary_search_on_house(nums1,myu);
            if(v.size()%2==0){
                return (double)((nums1[med]+nums1[med-1])/2);
            }
            else{
                return (double)nums1[med];
            }
        }
        else{
            int med = binary_search_on_house(nums2,myu);
            if(v.size()%2==0){
                return (double)((nums2[med]+nums2[med-1])/2);
            }
            else{
                return (double)nums2[med];
            }
        }

        
    }
};
// @lc code=end

