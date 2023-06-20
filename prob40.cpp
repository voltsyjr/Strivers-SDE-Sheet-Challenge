int removeDuplicates(vector<int> &arr,int n){
if(n==0 or n==1)return n;
int i=0;
for(int j=1;j<n;j++){
if(arr[j]!=arr[i]){
arr[i+1]=arr[j];
i++;
}
}
return i+1;
}
