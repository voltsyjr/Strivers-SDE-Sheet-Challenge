#include<bits/stdc++.h>
vector<vector<int>>mergeIntervels(vector<vector<int>>&intervals){
	int x=intervals[0][0],y=intervals[0][1];
vector<vector<int>>ans;
for(auto it:intervals){
if(it[0]<=y){
y=max(y,it[1]);
}else{
ans.push_back({x,y});
x=it[0],y=it[1];
}
}
ans.push_back({x,y});
return ans;
}