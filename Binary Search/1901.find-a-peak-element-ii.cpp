#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int findMaxRow(int mid, vector<vector<int>>& mat){
        int maxrow = 0;
        for(int i =0; i<mat.size(); i++){
            maxrow = mat[i][mid]>=mat[maxrow][mid] ? i : maxrow; // finding max in a column of a 2d array
        }
        return maxrow;
    }

    bool predicate(int mid, int leftcol, int rightcol, vector<vector<int>>& mat){
        int maxrow = findMaxRow(mid,mat);

        /// old logic a[mid]>a[mid+1] rret true
        if(
            // mat[maxrow][mid]>mat[maxrow+1][mid] WRONG!!! WE ARE DOING COLUMNS NOW
            mat[maxrow][mid]>mat[maxrow][mid+1]
            && mid+1<=rightcol){
            return true;
        }
        return false;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int leftcol = 0;
        int rightcol = mat[0].size()-1;
        while(leftcol<rightcol){
            int mid = (leftcol+rightcol)/2;

            if(predicate(mid,leftcol,rightcol,mat)){
                rightcol=mid;
            }
            else{
                leftcol= mid+1;
            }
        }
        int maxrow = findMaxRow(leftcol,mat);

        return vector<int>{maxrow,leftcol};

    }








    // bool predicate(int mx, int my, vector<vector<int>>& mat){
    //     if(mat[mx][my]>mat[mx+1][my]
    //     && mat[mx][my]>mat[mx][my+1]
    //     && mx + 1 < mat.size() 
    //     && my + 1 < mat[0].size()){
    //         return true;
    //     }
    //     return false;
    // }
    // vector<int> findPeakGrid(vector<vector<int>>& mat) {
    //     int lx = 0;
    //     int ly = 0;
    //     int rx = mat.size()-1;
    //     int ry = mat[0].size()-1;

    //     while(lx<rx && ly<ry){
    //         int mx = (lx+rx)/2;
    //         int my = (ly+ry)/2;

    //         if(predicate(mx,my,mat)){
    //             rx = mx;
    //             ry = my;
    //         }
    //         else{
    //             if(mat[mx][my]<mat[mx+1][my]
    //             && mx + 1 < mat.size()){
    //                 lx = mx+1;
    //             }
    //             else if(mat[mx][my]<mat[mx][my+1]
    //             && my + 1 < mat[0].size()){
    //                 ly = my+1;
    //             }
    //             else{
    //                 lx = mx+1;
    //                 ly = my+1;
    //             }
    //         }
    //     }

    //     return vector<int>{lx,ly};
    // }
};
// @lc code=end

