#include<bits/stdc++.h>
int maximumProfit(vector<int> &prices){
int minValue=INT_MAX;
int profit=0;
for(int i=0;i<prices.size();i++){
minValue=min(minValue,prices[i]);
profit=max(profit,prices[i]-minValue);
}
return profit;
}