#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isInsideCirle(int i, int j, int h, int k, int R){
    return (pow(i - h, 2) + pow(j - k, 2)) <= pow(R, 2);
}

bool bfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> vis, int xFinal, int yFinal,
vector<int> &h, vector<int> &k, int N, int R){
    queue<pair<int,int>> qu;
    qu.push({i,j});
    vis[i][j]=1;

    int dx[8]={0,0,1,-1,1,1,-1,-1};
    int dy[8]={1,-1,0,0,1,-1,1,-1};
    int m = grid.size();
    int n = grid[0].size();

    bool blocked = false;

    while(!qu.empty()){
        auto p = qu.front();
        int x = p.first;
        int y = p.second;

        if(x==xFinal && y == yFinal){
            return true;
        }


        for(int l =0; l<8;l++){
            int nx = x + dx[l];
            int ny = y + dy[l];
            bool valid = nx<m && nx>=0 && ny<n && ny>=0 && grid[nx][ny] == 0 && !vis[nx][ny];
            if(valid){

                for(int c = 0; c<N; c++){
                    if(isInsideCirle(x,y,h[c],k[c],R)){
                        blocked = true;
                        break;
                    }
                }

                if(!blocked){
                    qu.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
    }

    return blocked;
}
// Solution::
string solve(int x, int y, int N, int R, vector<int> &h, vector<int> &k) {
    int m = x+1;
    int n = y+1;
    vector<vector<int>> grid(m,vector<int>(n,0));
    vector<vector<int>> vis(m,vector<int>(n,0));

    // for(int circle = 0; circle<N; circle++){
    //     for(int i = 0; i<m; i++){
    //         for(int j = 0; j<n;j++){
    //             int xCentre = h[circle];
    //             int yCentre = k[circle];
    //             double dist = sqrt(pow(i - xCentre, 2) + pow(j - yCentre, 2));

    //             if(dist<=R){
    //                 grid[i][j]=1; // blocked
    //             }
    //         }
    //     }
    // }

    bool blocked = bfs(0,0,grid,vis,x,y,h,k, N, R);
    if(blocked == 1){
        return "NO";
    }
    else{
        return "YES";
    }

}