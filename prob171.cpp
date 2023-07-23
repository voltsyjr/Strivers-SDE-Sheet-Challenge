class Solution {
public:
    int edit(int i,int j,string s,string t,vector<vector<int>>&dp){
        if(i==0)return j;
        if(j==0)return i;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i-1]==t[j-1])return dp[i][j]= edit(i-1,j-1,s,t,dp);
        else return dp[i][j]=  1+min(edit(i,j-1,s,t,dp),min(edit(i-1,j,s,t,dp),edit(i-1,j-1,s,t,dp)));
    }
    int minDistance(string word1, string word2) {
       vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return edit(word1.size(),word2.size(),word1,word2,dp);
        if(word1=="")return word2.size();
        if(word2=="")return word1.size();
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
        // //base case
        for(int i=0;i<=word1.size();i++)dp[i][0]=i;
        for(int j=0;j<=word2.size();j++)dp[0][j]=j;
        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1])dp[i][j]= dp[i-1][j-1];
                else dp[i][j]=  1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }
        }
        return dp[word1.size()][word2.size()];



        //space optimization
        vector<int>prev(word2.size()+1,0),cur(word2.size()+1,0);
        for(int j=0;j<=word2.size();j++)prev[j]=j;
        for(int i=1;i<=word1.size();i++){
            cur[0]=i;
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1])cur[j]= prev[j-1];
                else cur[j]=  1+min(cur[j-1],min(prev[j],prev[j-1]));
            }
            prev=cur;
        }
        return prev[word2.size()];
    }
};