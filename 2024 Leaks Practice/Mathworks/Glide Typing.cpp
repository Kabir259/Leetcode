#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#include <string>
#include <vector>

class Solution {
public:
    // Function to check if str1 is a subsequence of str2
    bool isSubsequence(const string& str1, const string& str2) {
        int i = 0, j = 0;
        while (i < str1.length() && j < str2.length()) {
            if (str1[i] == str2[j]) {
                i++;
            }
            j++;
        }
        return i == str1.length();
    }

    string getValidWord(string s, vector<string>& dictionary) {
        string result = "-1";
        bool found = false;
        
        // Check each word in dictionary
        for (const string& word : dictionary) {
            // If word is a subsequence of s
            if (isSubsequence(word, s)) {
                // If we haven't found any valid word yet, or this word is lexicographically smaller
                if (!found || word < result) {
                    result = word;
                    found = true;
                }
            }
        }
        
        return result;
    }
};