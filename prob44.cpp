int calculateMinPatforms(int at[],int dt[],int n){
sort(at,at+n);
sort(dt,dt+n);
int p=1,ans=1;
int a=1,d=0;
while(a<n){
if(at[a]<=dt[d]){
p++;
ans=max(ans,p);
a++;
}else{
d++;
p=p-1;
}
}//end while
return ans;
}
