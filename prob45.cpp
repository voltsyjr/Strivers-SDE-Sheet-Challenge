
#include<bits/stdc++.h>
bool comparator(vector<int> v1,vector<int> v2){
if(v1[1]>v2[1])return true;
return false;
}
int jobScheduling(vector<vector<int>> &jobs){
int maxt=jobs[0][0];
for(auto it:jobs){
    maxt=max(maxt,it[0]);
}
sort(jobs.begin(),jobs.end(),comparator);
vector<int>d(maxt+1,-1);
int p=0;
for(int i=0;i<jobs.size();i++){
    if(d[jobs[i][0]]==-1){
        p+=jobs[i][1];
        d[jobs[i][0]]=1;
    }else{
        int j=jobs[i][0]-1;
        while(j>0){
            if(d[j]==-1){
                p+=jobs[i][1];
                d[j]=1;
                break;
            }else{
                j--;
            }
        }
    }
}
return p;
}
