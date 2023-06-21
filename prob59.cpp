class Solution{
    public:
    void pathing(vector<vector<int>> &m, int n,vector<string>&ans,vector<vector<int>>&vis
    ,int x,int y,string s){
        if(x==n-1 and y==n-1){
            ans.push_back(s);
            return;
        }
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nx=x+delRow[i];
            int ny=y+delCol[i];
            if(nx>=0 and ny>=0 and nx<n and ny<n and vis[nx][ny]==0 and m[nx][ny]==1){
                vis[nx][ny]=1;
                if(i==0){
                    pathing(m,n,ans,vis,nx,ny,s+"U");
                }else if(i==1){
                    pathing(m,n,ans,vis,nx,ny,s+"R");
                }else if(i==2){
                    pathing(m,n,ans,vis,nx,ny,s+"D");
                }else{
                    pathing(m,n,ans,vis,nx,ny,s+"L");
                }
                vis[nx][ny]=0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0]==0)return {};
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0]=1;
        pathing(m,n,ans,vis,0,0,"");
        sort(ans.begin(),ans.end());
        return ans;
    }
};