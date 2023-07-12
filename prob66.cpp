#include <bits/stdc++.h> 
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long l=time[0],r=0;
	for(auto it:time)l=min((long long)it,l),r+=it;
	long long ans=r;
	while(l<=r){
		long long m=(l+r)/2;
		long long days=1,singleDay=0;
		for(auto it:time){
			if(it>m){days=n+1;break;}
			if(singleDay+it<=m)singleDay+=it;
			else singleDay=it,days++;
		}
		if(days>n)l=m+1;
		else ans=m,r=m-1;
	}
	return ans;
}