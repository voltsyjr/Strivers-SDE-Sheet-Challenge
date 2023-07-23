class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size(),n2=text2.size();
        vector<vector<int>>lcs(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1])lcs[i][j]=1+lcs[i-1][j-1];
                else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
        int i=n1,j=n2;
        string s="";
        while(i>=1 and j>=1){
            
            if(lcs[i][j]==lcs[i-1][j])i--;
            else if(lcs[i][j]==lcs[i][j-1]) j--;
            else if(lcs[i][j]==1+lcs[i-1][j-1])s=text1[i-1]+s,i--,j--;
        }
        cout<<s;
        return lcs[n1][n2];
    }
};