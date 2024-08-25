/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:

    vector<string> neighbours(string s, unordered_set<string>& st){
        vector<string> ans;
       
        for(int i =0; i<s.size(); i++){
            for(char c = 'a'; c<='z'; c++){
                if (s[i] == c) continue;  // Avoid replacing a character with itself
                string newword = s;
                newword[i] = c;

                if(st.find(newword)!=st.end()){
                    ans.push_back(newword);
                }
            }
        }
        return ans;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        
        queue<pair<string,int>> q;
        q.push({beginWord,0});

        int depth;

        while(!q.empty()){
            auto x = q.front();
            string str = x.first;
            int d = x.second;
            if(str==endWord){
                depth=d;
                break;
            }
            for(auto n: neighbours(str,st)){
                q.push({n,d+1});
            }

        }
        return depth;
    }
};
// @lc code=end

