bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m=matrix.size(),n=matrix[0].size();
        for(int i=m-1;i>=0;i--){
            if(target>=matrix[i][0]){
                for(int j=0;j<n;j++){
                    if(target==matrix[i][j])return true;
                }
                return false;
            }
        }
        return false;
}