
int minCharsforPalindrome(string str) {
	int i=0,j=str.size()-1,trim=j,res=0;
	while(i<j){
		if(str[i]==str[j])i++,j--;
		else res++,i=0,j=--trim;
	}
	return res;
}
