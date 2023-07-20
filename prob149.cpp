#include<bits/stdc++.h>
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int m=image.size();
        int n=image[0].size();
        int c=image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vector<vector<int>>vis(m,vector<int>(n,0));
        vis[sr][sc]=1;
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        image[sr][sc]=color;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(auto it:dir){
                int x=node.first+it.first;
                int y=node.second+it.second;
                if(x>=0 and x<m and y>=0 and y<n and vis[x][y]==0 and image[x][y]==c){
                    vis[x][y]=1;
                    image[x][y]=color;
                    q.push({x,y});
                }
            }
        }
        return image;
}