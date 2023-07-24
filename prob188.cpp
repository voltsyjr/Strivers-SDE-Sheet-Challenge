sort(arr.begin(),arr.end());
	vector<pair<int,pair<int,int>>>oQ;
	int q=queries.size();
	for(int i=0;i<q;i++){
		oQ.push_back({queries[i][1],{queries[i][0],i}});
	}
	sort(oQ.begin(),oQ.end());
	vector<int>ans(q,0);
	Trie T;
	int n=arr.size();
	int ind=0;
	for(int i=0;i<q;i++){
		int ai=oQ[i].first;
		int xi=oQ[i].second.first;
		int qind=oQ[i].second.second;
		while(ind<n and arr[ind]<=ai){
			T.insert(arr[ind]);
			ind++;
		}
		if(ind==0)ans[qind]=-1;
		else ans[qind]=T.getmax(xi);
	}
	return ans;