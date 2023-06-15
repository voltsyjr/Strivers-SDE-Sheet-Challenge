#include<bits/stdc++.h>
long long merge(long long *arr,vector<long long>&temp,long long l,long long m,long long r){
long long counts=0;
long long i=l,j=m,k=l;
while(i<m and j<=r){
if(arr[i]<arr[j]){
temp[k]=arr[i];
k++;i++;
}else{
temp[k]=arr[j];
counts+=m-i;
j++;k++;
}
}
while(i<m){
temp[k]=arr[i];
k++;i++;
}
while(j<=r){
temp[k]=arr[j];
k++;j++;
}
for(long long i=l;i<=r;i++){
arr[i]=temp[i];
}
return counts;
}
long long mergeSort(long long *arr,vector<long long>&temp,long long l,long long r){
long long counts=0,mid=(l+r)/2;
if(r>l){
counts+=mergeSort(arr,temp,l,mid);
counts+=mergeSort(arr,temp,mid+1,r);
counts+=merge(arr,temp,l,mid+1,r);
}
return counts;
}
long long getInversions(long long *arr,int n){
vector<long long> temp(n+1,0);
return mergeSort(arr,temp,0,n-1);
}
