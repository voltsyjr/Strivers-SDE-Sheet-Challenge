#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	int ans=INT_MIN,pref=1,suf=1;
	for(int i=0;i<n;i++){
		pref*=arr[i];
		suf*=arr[n-i-1];
		ans=max(pref,ans);
		ans=max(ans,suf);
		if(pref==0)pref=1;
		if(suf==0)suf=1;
	}
	return ans;
}
