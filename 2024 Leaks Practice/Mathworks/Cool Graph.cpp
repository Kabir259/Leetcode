#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    vector<int> coolGraph(int g_nodes, vector<int> g_from, vector<int> g_to) {
        // Create adjacency list representation
        vector<vector<int>> adj(g_nodes + 1);  // 1-based indexing
        for(int i = 0; i < g_from.size(); i++) {
            adj[g_from[i]].push_back(g_to[i]);
            adj[g_to[i]].push_back(g_from[i]);  // Undirected graph
        }
        
        // Function to get all possible DFS traversals
        vector<vector<int>> allTraversals;
        
        auto dfs = [&](auto& self, vector<bool>& visited, vector<int>& path) -> void {
            if(path.size() == g_nodes) {
                allTraversals.push_back(path);
                return;
            }
            
            // Try all neighbors
            for(int node = 1; node <= g_nodes; node++) {
                if(!visited[node]) {
                    // Check if this node is connected to the last node in path
                    bool isConnected = path.empty() || 
                        find(adj[path.back()].begin(), adj[path.back()].end(), node) != adj[path.back()].end();
                    
                    if(isConnected) {
                        visited[node] = true;
                        path.push_back(node);
                        self(self, visited, path);
                        path.pop_back();
                        visited[node] = false;
                    }
                }
            }
        };
        
        // Generate all possible valid traversals
        vector<bool> visited(g_nodes + 1, false);
        vector<int> path;
        dfs(dfs, visited, path);
        
        // Function to generate array B from a traversal A
        auto generateB = [](const vector<int>& A) -> vector<int> {
            vector<int> B;
            for(int i = 0; i < A.size(); i++) {
                bool found = false;
                for(int j = 0; j < B.size(); j++) {
                    if(A[i] == B[j]) {
                        found = true;
                        break;
                    }
                }
                if(!found) {
                    B.push_back(A[i]);
                }
            }
            return B;
        };
        
        // Find traversal that generates lexicographically largest B
        vector<int> bestB;
        for(const auto& traversal : allTraversals) {
            vector<int> currentB = generateB(traversal);
            if(currentB > bestB) {
                bestB = currentB;
            }
        }
        
        return bestB;
    }
};