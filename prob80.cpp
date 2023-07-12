vector<int> nextGreaterElements(vector<int>& arr) {
        stack<int>st;
	vector<int>ans={};
    int n=arr.size();
	for(int i=2*n-1;i>=0;i--){
		while(!st.empty() and st.top()<=arr[i%n])st.pop();
		if(st.empty())ans.push_back(-1);
		else ans.push_back(st.top());
		st.push(arr[i%n]);
	}
	reverse(ans.begin(),ans.end());
	vector<int>res;
	for(int i=0;i<n;i++){
		res.push_back(ans[i]);
	}
	return res;
    }