#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    int l=max(0,k-n),h=min(k,m);
    if(n<m)return ninjaAndLadoos(row2,row1,n,m,k);
    while(l<=h){
        int cnt1=(l+h)>>1;
        int cnt2=k-cnt1;
        int l1,l2,r1,r2;
        l1=cnt1==0?INT_MIN:row1[cnt1-1];
        l2=cnt2==0?INT_MIN:row2[cnt2-1];
        r1=cnt1==m?INT_MAX:row1[cnt1];
        r2=cnt2==n?INT_MAX:row2[cnt2];
        if(l1<=r2 and l2<=r1){
            return max(l1,l2);
        }else if(l1>r2)h=cnt1-1;
        else l=cnt1+1;
    }
    return 0;
}