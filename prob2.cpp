#include <bits/stdc++.h>

vector<vector<long long int >>printPascal(int n){
if(n==1)return {{1}};
if(n==1) return {{1},{1,1}};
vector<vector<long long int>>pascal={{1},{1,1}};
vector<long long int>prev={1,1};
for(int i=2;i<n;i++){
vector<long long int>cur;
for(int j=0;j<=i;j++){
if(j==0){cur.push_back(1);continue;}
if(j==i){cur.push_back(1);continue;}
cur.push_back(prev[j]+prev[j-1]);
}
pascal.push_back(cur);
prev=cur;
}
return pascal;
}