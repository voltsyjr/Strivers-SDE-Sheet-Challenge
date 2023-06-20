#include <bits/stdc++.h> 
void rec(vector<string>&ans,string &temp,string&s,int ind){
    if(ind==s.size()){ans.push_back(temp);return;}
    for(int i=ind;i<s.size();i++){
        swap(s[ind],s[i]);
        temp+=s[ind];
        rec(ans,temp,s,ind+1);
        temp.pop_back();
        swap(s[ind],s[i]);
    }
    return;
}
vector<string> findPermutations(string &s) {
    vector<string>ans;
    string temp="";
    rec(ans,temp,s,0);
    return ans;
}