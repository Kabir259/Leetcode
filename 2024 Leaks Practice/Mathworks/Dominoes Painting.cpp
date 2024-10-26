#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
    const int MOD = 1000000007;
    vector<string> dominoes;
    vector<vector<int>> adj;  // Adjacency list
    
    // Helper function to check if two dominoes are adjacent
    bool isAdjacent(const vector<vector<char>>& grid, int d1, int d2) {
        int rows = grid.size();
        int cols = grid[0].size();
        char c1 = dominoes[d1][0];  // First char of domino 1
        char c2 = dominoes[d2][0];  // First char of domino 2
        
        // Check each position in grid
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == c1) {
                    // Check all 4 directions
                    if(i > 0 && grid[i-1][j] == c2) return true;
                    if(i < rows-1 && grid[i+1][j] == c2) return true;
                    if(j > 0 && grid[i][j-1] == c2) return true;
                    if(j < cols-1 && grid[i][j+1] == c2) return true;
                }
            }
        }
        return false;
    }
    
    // Build adjacency list for dominoes
    void buildGraph(const vector<vector<char>>& grid) {
        int n = dominoes.size();
        adj.resize(n);
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(isAdjacent(grid, i, j)) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    }
    
    // Try to color graph with 3 colors
    int countValidColorings(vector<int>& colors, int pos) {
        if(pos == colors.size()) {
            return 1;  // Found a valid coloring
        }
        
        long long count = 0;
        // Try each color (0=R, 1=G, 2=B)
        for(int c = 0; c < 3; c++) {
            bool valid = true;
            // Check if this color works with adjacent dominoes
            for(int adj_domino : adj[pos]) {
                if(adj_domino < pos && colors[adj_domino] == c) {
                    valid = false;
                    break;
                }
            }
            
            if(valid) {
                colors[pos] = c;
                count = (count + countValidColorings(colors, pos + 1)) % MOD;
            }
        }
        
        return count;
    }

public:
    int getDominoColors(vector<string>& domino) {
        dominoes = domino;
        
        // Create grid representation
        int rows = 2;
        int cols = domino[0].size();
        vector<vector<char>> grid(rows, vector<char>(cols));
        
        // Fill grid
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                grid[i][j] = domino[i][j];
            }
        }
        
        // Build graph of adjacent dominoes
        buildGraph(grid);
        
        // Count valid colorings
        vector<int> colors(dominoes.size(), -1);
        return countValidColorings(colors, 0);
    }
};