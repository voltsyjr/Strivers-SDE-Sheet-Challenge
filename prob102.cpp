string say(string s){
        string ans="";
        int i=0;
        int cnt=1;
        while(i<s.size()-1){
            if(s[i]==s[i+1]){
                cnt++;
            }else{
                ans=ans+to_string(cnt)+s[i];
                cnt=1;
            }
            i++;
        }
        if(i>0 and s[i]!=s[i-1])cnt=1;
        ans=ans+to_string(cnt)+s[i];
        return ans;
    }
    string lookAndSaySequence(int n) {
        if(n==1)return "1";
        string s="1";
        for(int i=1;i<n;i++){
            s=say(s);
        }
        return s;
    }