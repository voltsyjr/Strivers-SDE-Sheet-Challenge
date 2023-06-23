int upperBound(vector<int>&row,int val){
int low=0,high=row.size()-1;
while(low<=high){
int mid=(low+high)>>1;
if(row[mid]<=val){
low=mid+1;
}else{
high=mid-1;
}
}
return low;
}
int getMedian(vector<vector<int>> &matrix){
int n=matrix.size(),m=matrix[0].size();
int low=1,high=1e9;
while(low<=high){
int mid=(low+high)>>1;
int cnt=0;
for(int i=0;i<n;i++){
    cnt+=upperBound(matrix[i],mid);
}
if(cnt>(n*m)>>1)high=mid-1;
else low=mid+1;
}
}
