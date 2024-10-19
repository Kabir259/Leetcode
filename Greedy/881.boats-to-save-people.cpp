/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i,j;
        i = 0;
        j = people.size()-1;

        int boats = 0;

        while(i<=j){
            if(people[i]+people[j]<=limit){
                // boats++;
                i++;
                j--;
            }
            else{
                j--;
            }
            boats++;
        }
        return boats;
    }
};
// @lc code=end

