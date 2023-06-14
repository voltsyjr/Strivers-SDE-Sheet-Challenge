#include <bits/stdc++.h>

void setZeros(vector<vector<int>>& matrix) {
        int col=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(j==0 and matrix[i][j]==0){col=1;continue;}
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=matrix.size()-1;i>=0;i--){
            for(int j=matrix[0].size()-1;j>=0;j--){
                if(j==0){
                    if(col==1)
                    matrix[i][j]=0;continue;
                    }
                else if(matrix[i][0]==0 or matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
