#include <bits/stdc++.h> 
bool isPalindrome(string s,int l,int r){
    while(l<=r){
        if(s[l]!=s[r])return false;
        l++,r--;
    }
    return true;
}
void rec(vector<vector<string>>&ans,string &s,int ind,vector<string>&temp){
if(ind>=s.size()){
    ans.push_back(temp);
    return;
}
for(int i=ind;i<s.size();i++){
        if(isPalindrome(s,ind,i)){
            string subs=s.substr(ind,(i-ind)+1);
            temp.push_back(subs);
            rec(ans,s,i+1,temp);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    if(s.size()==0)return {{}};
    vector<vector<string>>ans;
    vector<string>temp;
    for(int i=0;i<s.size();i++){
        if(isPalindrome(s,0,i)){
            string subs=s.substr(0,i+1);
            temp.push_back(subs);
            rec(ans,s,i+1,temp);
            temp.pop_back();
        }
    }
    return ans;
}