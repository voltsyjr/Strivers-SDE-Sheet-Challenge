int singleNonDuplicate(vector<int>& arr)
{
	int l=0,r=arr.size()-2;
	while(l<=r){
		int m=(l+r)>>1;
		if(arr[m]==arr[m^1]){
			 l=m+1;
		}else{
			 r=m-1;
		}
	}
	return arr[l];
}