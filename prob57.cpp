
bool isValid(int matrix[9][9],int row,int col,int val){
for(int i=0;i<9;i++){
if(matrix[row][i]==val)return false;
if(matrix[i][col]==val)return false;
if(matrix[3*(row/3)+i/3][3*(col/3)+i%3]==val)return false;
}
return true;
}
bool solve(int matrix[9][9]){
for(int i=0;i<9;i++){
for(int j=0;j<9;j++){
if(matrix[i][j]==0){
for(int val=1;val<=9;val++){
if(isValid(matrix,i,j,val)){
matrix[i][j]=val;
if(solve(matrix))return true;
matrix[i][j]=0;
}//end if
}//end for
return false;
}//end if
}//end j for
}//end outer for
}

bool isItSudoku(int matrix[9][9]){
return solve(matrix);
}
