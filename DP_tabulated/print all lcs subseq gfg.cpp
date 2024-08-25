//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:       

        // Helper function to backtrack and find all LCS
        // vector<string> backtrack(int i, int j, string lcs, vector<vector<int>>& dp, string& s, string& t) {
        //     if (i == 0 || j == 0) {
        //         return {lcs};
        //     }
            
        //     if (s[i - 1] == t[j - 1]) {
        //         return backtrack(i - 1, j - 1, s[i - 1] + lcs, dp, s, t);
        //     }
            
        //     vector<string> res;
        //     if (dp[i - 1][j] == dp[i][j]) {
        //         vector<string> temp = backtrack(i - 1, j, lcs, dp, s, t);
        //         res.insert(res.end(), temp.begin(), temp.end());
        //     }
            
        //     if (dp[i][j - 1] == dp[i][j]) {
        //         vector<string> temp = backtrack(i, j - 1, lcs, dp, s, t);
        //         res.insert(res.end(), temp.begin(), temp.end());
        //     }
            
        //     // Remove duplicates by using an unordered_set
        //     unordered_set<string> unique_res(res.begin(), res.end());
        //     return vector<string>(unique_res.begin(), unique_res.end());
        // }


        vector<string> backtrack(int i, int j, string lcs, vector<vector<int>>& dp, string& s, string& t){
            if(i==0 && j==0){
                return {lcs}; // vector elt banade sting ka and then return kar
            }

            if(s[i-1]==t[j-1]){
                
            }
        }

		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    string text1 = s;
		    string text2 = t;
		    
		    int m = text1.size();
            int n = text2.size();
            
            vector<string> ans;

            vector<vector<int>> dp(m+1,vector<int>(n+1));
            for (int i = 0; i <=m ; i++)
            {
                for (int j = 0; j <= n; j++)
                {
                    if(i==0 || j==0){
                        dp[i][j]=0;
                    }
                }            
            }

            for (int i = 1; i <=m ; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if(text1[i-1]==text2[j-1]){
                        dp[i][j]=1+dp[i-1][j-1];
                        
                    }
                    else{
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }            
            }       
            

        vector<string> lcsList = backtrack(m, n, "", dp, text1, text2);
        
        // Sort the results lexicographically if needed
        sort(lcsList.begin(), lcsList.end());
        
        return lcsList;

        }
    };



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends