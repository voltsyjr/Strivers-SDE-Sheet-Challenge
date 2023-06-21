#include <bits/stdc++.h> 
bool isValid(vector<vector<int>>&mat,vector<int>&colors,int node,int c){
    for(int i=0;i<mat.size();i++){
        if(mat[i][node]==1 and colors[i]==c and i!=node)return false;
    }
    return true;
}
bool solve(vector<vector<int>>&mat,vector<int>&colors,int m,int node){
    if(node==mat.size())return true;
    for(int c=1;c<=m;c++){
        if(isValid(mat,colors,node,c)){
            colors[node]=c;
            if(solve(mat,colors,m,node+1))return true;
            colors[node]=0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    vector<int>colors(mat.size(),-1);
    if(solve(mat,colors,m,0))return "YES";
    else return "NO";
}