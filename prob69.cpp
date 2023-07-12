#include <bits/stdc++.h> 
void min_Heapify(vector<int>&heap,int index){
    int smallest=index,left=2*index+1,right=2*index+2,size=heap.size();
    if(left<size and heap[left]<heap[index])smallest=left;
    if(right<size and heap[right]<heap[smallest]) smallest=right;
    if(smallest!=index){
        swap(heap[smallest],heap[index]);
        min_Heapify(heap,smallest);
    }
    return ;
}
void insert_Min_Heap(vector<int>&heap,int val){
    heap.push_back(val);
    int i=heap.size()-1;
    while(i>0 and heap[(i-1)/2]>heap[i]){
        swap(heap[i],heap[(i-1)/2]);
        i=(i-1)/2;
    }
    return ;
}
int extract_Min_Heap(vector<int>&heap){
    int top=heap[0];
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    min_Heapify(heap,0);
    return top;
}
vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int>heap,ans;
    for(auto it:q){
        if(it[0]==0){
            insert_Min_Heap(heap,it[1]);
        }else{
            if(heap.size()==0){ans.push_back(0);continue;}
            ans.push_back(heap[0]);
            extract_Min_Heap(heap);
        }
    }
    return ans;
}
