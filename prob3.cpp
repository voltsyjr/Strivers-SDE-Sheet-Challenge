#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    if(n<=1)return permutation;
vector<int>ans=permutation;
int i=n-2;
while(ans[i]>=ans[i+1])i--;
if(i>=0){
int j=n-1;
while(j>=0 and ans[i]>=ans[j])j--;
swap(ans[i],ans[j]);
}
reverse(ans.begin()+i+1,ans.end());
return ans;
}