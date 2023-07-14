string commonPrefix(vector<string>& arr,int n){
	string temp=arr[0];
    int i=0,c=temp.size();
    for(int j=1;j<n;j++){
        while(i<c and i<arr[j].size() and temp[i]==arr[j][i])i++;
        c=i,i=0;
    }
    return c==0?"-1":temp.substr(0,c);
}


