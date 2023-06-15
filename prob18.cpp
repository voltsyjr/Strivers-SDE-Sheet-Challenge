#include<bits/stdc++.h>
int merge(vector<int>&arr,vector<int>&temp,int l,int m,int r){
int i=l,j=m,count=0,k=l;
while(i<m and j<=r){
if(arr[i]>(long)2*arr[j]){
count+=m-i;
j++;
}else{
i++;
}
}
i=l,j=m,k=l;
while(i<m and j<=r){
if(arr[i]<arr[j]){
temp[k++]=arr[i++];
}else{
temp[k++]=arr[j++];
}
}
while(i<m){
temp[k++]=arr[i++];
}
while(j<=r){
temp[k++]=arr[j++];
}
for(int i=l;i<=r;i++){
arr[i]=temp[i];
}
return count;
}
int mergeSort(vector<int>&arr,vector<int>&temp,int l,int r){
int count=0,mid=(l+r)/2;
if(r>l){
count+=mergeSort(arr,temp,l,mid);
count+=mergeSort(arr,temp,mid+1,r);
count+=merge(arr,temp,l,mid+1,r);
}
return count;
}
int reversePairs(vector<int> &arr,int n){
vector<int>temp(n,0);
return mergeSort(arr,temp,0,n-1);
}
