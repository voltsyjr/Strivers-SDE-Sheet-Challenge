#include <bits/stdc++.h> 
bool isValid(string s,unordered_map<string,int>&mp){
    if(mp.find(s)==mp.end())return false;
    return true;
}
void solve(string &s,unordered_map<string,int>&mp,int ind,string &temp,vector<string>&ans){
    if(ind==s.size()){
        ans.push_back(temp);
        return;
    }
    string rep=temp;
    for(int i=ind;i<s.size();i++){
        string subs=s.substr(ind,(i-ind)+1);
        if(isValid(subs,mp)){
            if(ind==0)temp=temp+subs;
            else 
            temp=temp+" "+subs;
            solve(s,mp,i+1,temp,ans);
            temp=rep;
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string>ans;
    unordered_map<string,int>mp;
    for(auto it:dictionary)mp[it]=1;
    string temp="";
    solve(s,mp,0,temp,ans);
    sort(ans.begin(),ans.end());
    return ans;
}