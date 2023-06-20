#include<bits/stdc++.h>
struct meetings{
int start,end,pos;
};
bool comparator(struct meetings m1,struct meetings m2){
if(m1.end<m2.end)return true;
else if(m1.end>m2.end)return false;
else if(m1.pos<m2.pos)return true;
else return false;
}
vector<int>maximumMeetings(vector<int>&start,vector<int>&end){
int n=start.size();
struct meetings meet[n];
for(int i=0;i<n;i++){
meet[i].start=start[i],meet[i].end=end[i],meet[i].pos=i+1;
}
sort(meet,meet+n,comparator);
vector<int>ans;
int limit=meet[0].end;
ans.push_back(meet[0].pos);
for(int i=1;i<n;i++){
if(meet[i].start>limit){
ans.push_back(meet[i].pos);
limit=meet[i].end;
}
}
return ans;
}
