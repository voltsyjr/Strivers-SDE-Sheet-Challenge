vector<vector<int>> pairSum(vector<int> &nums, int target){
   unordered_map<int,int>mp;
   vector<vector<int>>ans;
       for(int i=0;i<nums.size();i++){
           int n1=nums[i];
           int n2=target-n1;
           if(mp.find(n2)!=mp.end()){
              for(int i=0;i<mp[n2];i++){
               if(n1<n2)
                  ans.push_back({n1,n2});              
                  else  ans.push_back({n2,n1});
              }

           }
           mp[n1]++;
       }
       sort(ans.begin(),ans.end());
       return ans;
}