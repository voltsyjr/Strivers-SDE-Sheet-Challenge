class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int maxi=1,l=0;
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            if(i+1<n)
                if(s[i]==s[i+1]){
                    dp[i][i+1]=1;
                    if(2>maxi)maxi=2,l=i;
                }else dp[i][i+1]=0;
        }
        for(int d=2;d<n;d++){
            for(int i=0;i<n-d;i++){
                if(s[i]==s[i+d] and dp[i+1][i+d-1]==1){
                    dp[i][i+d]=1;
                    if(d+1>maxi)maxi=d+1,l=i;
                }
            }
        }
        return s.substr(l,maxi);
    }
};