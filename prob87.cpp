#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int m, int n)
{
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        int time=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            time=max(time,node.second);
            for(auto it:dir){
                int x=it.first+ node.first.first;
                int y=it.second +node.first.second;
                int t=node.second;
                if(x>=0 and x<m and y>=0 and y<n and vis[x][y]==0 and grid[x][y]==1){
                    vis[x][y]=1;
                    grid[x][y]=2;
                    q.push({{x,y},t+1});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
}