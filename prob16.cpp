#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &nums)
{
    int n=nums.size();
    int n1=-1,n2=-1,c1=0,c2=0;
    for(auto it:nums){
        if(it==n1)c1++;
        else if(it==n2)c2++;
        else if(c1==0)n1=it,c1=1;
        else if(c2==0)n2=it,c2=1;
        else c1--,c2--;
    }
    vector<int>ans;
    c1=0,c2=0;
    for(auto it:nums){
        if(it==n1)c1++;
        if(it==n2)c2++;
    }
    if(c1>n/3)ans.push_back(n1);    if(c2>n/3)ans.push_back(n2);
    return ans;

}