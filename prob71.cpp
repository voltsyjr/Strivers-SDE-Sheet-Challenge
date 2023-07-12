#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	priority_queue<pair<int,int>>mxheap;
	for(auto it:a){
		mxheap.push({it+b[n-1],n-1});
	}
	vector<int>ans;
	while(k-- and !mxheap.empty()){
		int sum=mxheap.top().first;
		int pos=mxheap.top().second;
		mxheap.pop();
		ans.push_back(sum);
		if(pos-1>=0) mxheap.push({sum-b[pos]+b[pos-1],pos-1});
	}
	return ans;
}