#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int>v)
{
    int n=v.size();
    int numEnd=pow(2,n);
    vector<vector<int>>ans;
    for(int num=0;num<numEnd;num++){
        vector<int>temp;
        for(int i=0;i<n;i++){
            if(num & (1<<i)){
                temp.push_back(v[i]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}