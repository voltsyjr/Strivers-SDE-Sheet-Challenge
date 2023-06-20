void solve(vector<vector<int>>&ans,vector<string>&board,vector<int>&leftRow,vector<int>&lowerDiagonal,vector<int>&upperDiagonal,int col){
int n=board.size();
if(col==n){
vector<int>t;
for(auto it:board){
for(auto it2:it){
if(it2=='.')t.push_back(0);
else t.push_back(1);
}
}
ans.push_back(t);
return;
}
for(int row=0;row<n;row++){
if(leftRow[row]==0 and lowerDiagonal[row+col]==0 and upperDiagonal[n-1+row-col]==0){
board[row][col]='Q';
leftRow[row]=1;
lowerDiagonal[row+col]=1;
upperDiagonal[n-1+row-col]=1;
solve(ans,board,leftRow,lowerDiagonal,upperDiagonal,col+1);
board[row][col]='.';
leftRow[row]=0;
lowerDiagonal[row+col]=0;
upperDiagonal[n-1+row-col]=0;
}//end if
}
}
vector<vector<int>>solveNQueens(int n){
vector<vector<int>>ans;
vector<string>board;
string s(n,'.');
for(int i=0;i<n;i++){
board.push_back(s);
}
vector<int>leftRow(n,0),lowerDiagonal(2*n,0),upperDiagonal(2*n,0);
solve(ans,board,leftRow,lowerDiagonal,upperDiagonal,0);
return ans;
}
