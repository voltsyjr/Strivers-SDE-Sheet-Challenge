#include<bits/stdc++.h>
string reverseString(string &str){
	int i=str.size()-1;
	string ans="";	
	while(str[i]==' ')i--;
	while(i>=0){
		int j=i-1;
		while(j>=0 and str[j]!=' ')j--;
		j++;
		for(int k=j;k<=i;k++)ans+=str[k];
		ans+=' ';
		i=j-1;
		while(i>=0 and str[i]==' ')i--;
	}
	return ans;
}