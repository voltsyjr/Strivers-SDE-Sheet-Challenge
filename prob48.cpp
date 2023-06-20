#include<bits/stdc++.h>
int maximumActivities(vector<int> &start,vector<int>&finish){
vector<pair<int,int>>d;
for(int i=0;i<start.size();i++)d.push_back({finish[i],start[i]});
sort(d.begin(),d.end());
int a=1,limit=d[0].first;
for(int i=1;i<d.size();i++){
if(d[i].second>=limit)a++,limit=d[i].first;
}
return a;
}
