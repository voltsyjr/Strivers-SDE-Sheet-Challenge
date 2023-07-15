
void generateLPS(vector<int>&lps,string &p){
	int i=1,j=0;
	lps.push_back(0);//first two are zeroes;
	while(i<p.size()){
		if(p[i]==p[j])j++,lps.push_back(j),i++;
		else{
			if(j!=0)j=lps[j-1];
			else lps.push_back(0),i++;
		}
	}
	
}
vector<int> stringMatch(string s, string p) {
	int n=s.size(),m=p.size();
	vector<int>lps;
	generateLPS(lps,p);
	vector<int>ans;
	int i=0;//for s
	int j=0;//for p
	while(i<s.size()){
		if(s[i]==p[j]){
			i++,j++;
			if(j==m)ans.push_back(i-m+1);
		}else{
			if(j!=0)j=lps[j-1];
			else i++;
		}
	}
	return ans;
}
 