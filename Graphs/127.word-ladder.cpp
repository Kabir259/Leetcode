#include <unordered_set>
#include <queue>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> getNeighbors(const string& s, const unordered_set<string>& st) {
        vector<string> neighbors;
        string newWord = s;
        for (int i = 0; i < s.size(); i++) {
            char originalChar = s[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == originalChar) continue;  // Skip replacing a char with itself
                newWord[i] = c;
                if (st.find(newWord) != st.end()) {
                    neighbors.push_back(newWord);
                }
            }
            newWord[i] = originalChar;  // Restore the original character
        }
        return neighbors;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;  // End word must be in the word list
        
        unordered_set<string> visited;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        visited.insert(beginWord);
        
        while (!q.empty()) {
            auto [word, length] = q.front();
            q.pop();
            
            if (word == endWord) return length;
            
            for (const string& neighbor : getNeighbors(word, wordSet)) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push({neighbor, length + 1});
                }
            }
        }
        
        return 0;  // If no transformation sequence is found
    }
};
