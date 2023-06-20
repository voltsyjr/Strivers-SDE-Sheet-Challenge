#include<bits/stdc++.h>
int findMinimumCoins(int amount){
int ans=0;
vector<int>r={1,2,5,10,20,50,100,500,1000};
for(int i=8;i>=0;i--){
if(amount>=r[i]){
ans+=amount/r[i];
amount=amount-((int)(amount/r[i]))*r[i];
}
}
return ans;
}
