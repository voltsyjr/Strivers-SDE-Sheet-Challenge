class Solution {
public:
    void max_heapify(vector<int>&nums,int index,int size){
        int largest=index,left=2*index+1,right=2*index+2;
        if(left<size and nums[left]>nums[index])largest=left;
        if(right<size and nums[right]>nums[largest])largest=right;
        if(largest!=index){
            swap(nums[largest],nums[index]);
            max_heapify(nums,largest,size);
        }
        return ;
    }
    void build_max_heap(vector<int>&nums){
        for(int i=nums.size()/2-1;i>=0;i--){
            max_heapify(nums,i,nums.size());
        }
        return ;
    }
    void heapSort(vector<int>&nums){
        build_max_heap(nums);
        for(int i=nums.size()-1;i>=1;i--){
            swap(nums[i],nums[0]);
            max_heapify(nums,0,i);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        heapSort(nums);
        return nums[nums.size()-k];
    }
};