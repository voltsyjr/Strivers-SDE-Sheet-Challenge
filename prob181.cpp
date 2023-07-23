void rec(int ind,string s,set<string> &st,vector<string>&ans,string &temp){
    if(ind==s.size()){
        ans.push_back(temp);
        return;
    }

    string rep=temp;
    for(int i=ind;i<s.size();i++){
        string sub=s.substr(ind,i-ind+1);
        if(st.find(sub)!=st.end()){
            if(ind!=0)
            temp+=" "+sub;
            else temp=sub;
            rec(i+1,s,st,ans,temp);
            temp=rep;
        }
    }
}
vector<string> getAllValidSentences(string &s, vector<string> &dict)
{
    vector<string>ans;
    set<string>st={dict.begin(),dict.end()};
    string temp="";
    rec(0,s,st,ans,temp);
    return ans;
}