#include<bits/stdc++.h>
class heap{
    public:
    priority_queue<int>mxheap;
priority_queue<int,vector<int>,greater<int>>minheap;
void insert(int val){
    if(mxheap.size()==minheap.size()){
        if(mxheap.size()==0){mxheap.push(val);
        return;}
        if(val<mxheap.top())mxheap.push(val);
        else minheap.push(val);
    }else{
        if(mxheap.size()>minheap.size()){
            if(val>=mxheap.top())minheap.push(val);
            else{
                int top=mxheap.top();
                mxheap.pop();
                minheap.push(top);
                mxheap.push(val);
            }
        }else{
            if(val<=minheap.top())mxheap.push(val);
            else{
                int top=minheap.top();
                minheap.pop();
                mxheap.push(top);
                minheap.push(val);
            }
        }
    }
}
int median(){
    if(mxheap.size()==minheap.size())return (mxheap.top()+minheap.top())/2;
    if(mxheap.size()>minheap.size())return mxheap.top();
    return minheap.top();
}
};
void findMedian(int *arr, int n){
    vector<int>ans;
    heap *obj=new heap();
	for(int i=0;i<n;i++){
        obj->insert(arr[i]);
        ans.push_back(obj->median());
    }
    for(auto it:ans)cout<<it<<" ";
}
