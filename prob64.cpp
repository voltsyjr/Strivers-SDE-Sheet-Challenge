double median(vector<int>& a, vector<int>& b) {
	int n1=a.size(),n2=b.size();
	int low=0,high=n1,n3=n1+n2;
	while(low<=high){
		int cut1=(low+high)>>1;
		int cut2=(n3+1)/2-cut1;
		int l1,l2,r1,r2;
		l1=cut1==0?INT_MIN:a[cut1-1];
		l2=cut2==0?INT_MIN:b[cut2-1];
		r1=cut1==n1?INT_MAX:a[cut1];
		r2=cut2==n2?INT_MAX:b[cut2];
		if(l1<=r2 and l2<=r1){
			if(n3%2==1)return max(l1,l2);
			else return (double)(max(l1,l2)+min(r1,r2))/2;
		}
		else if(l1>r2){
			high=cut1-1;
		}else{
			low=cut1+1;
		}
	}
	return 0;
}