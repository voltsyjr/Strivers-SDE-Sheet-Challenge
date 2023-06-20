void rec(vector<vector<int>>&ans,vector<int>&temp,int i,long long int sum,int k,int n,vector<int>&arr){
if(i>=n){
if(sum==k)ans.push_back(temp);
return;
}
temp.push_back(arr[i]);
rec(ans,temp,i+1,sum+arr[i],k,n,arr);
temp.pop_back();
rec(ans,temp,i+1,sum,k,n,arr);
return;
}
vector<vector<int>>findSubsetsThatSumToK(vector<int>arr,int n,int k){
vector<vector<int>>ans;
vector<int>temp;
rec(ans,temp,0,0,k,n,arr);
return ans;
}
