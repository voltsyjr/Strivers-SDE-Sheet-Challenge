#include<bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
	if(n==0) return {};
    priority_queue<int>mxheap;
	priority_queue<int,vector<int>,greater<int>>minheap;
	vector<int>ans={arr[0]};
	mxheap.push(arr[0]);
	for(int i=1;i<n;i++){
		if(mxheap.size()==minheap.size()){
			if(arr[i]>mxheap.top())minheap.push(arr[i]);
			else mxheap.push(arr[i]);
		}else{
			if(mxheap.size()>minheap.size()){
				if(arr[i]>=mxheap.top())minheap.push(arr[i]);
                else {
					int top=mxheap.top();
					mxheap.pop();
					minheap.push(top);
					mxheap.push(arr[i]);
                }
            }else{
				if(arr[i]<=minheap.top())mxheap.push(arr[i]);
				else{
					int top=minheap.top();
					minheap.pop();
					mxheap.push(top);
					minheap.push(arr[i]);
				}
			}
		}
		if(minheap.size()==mxheap.size())ans.push_back((minheap.top()+mxheap.top())/2);
        else {
            if (minheap.size() > mxheap.size())ans.push_back(minheap.top());
			else ans.push_back(mxheap.top());
        }
    }
	return ans;
}
