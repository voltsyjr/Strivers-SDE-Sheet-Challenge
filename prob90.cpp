#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int>ans(n,INT_MIN);
    vector<int>ls,rs;
    stack<int>st;
    st.push(0);
    ls.push_back(-1);
    for(int i=1;i<n;i++){
        while(!st.empty() and a[st.top()]>=a[i])st.pop();
        if(st.empty())ls.push_back(-1);
        else ls.push_back(st.top());
        st.push(i);
    }
    while(!st.empty())st.pop();
    st.push(n-1);
    rs.push_back(n);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() and a[st.top()]>=a[i])st.pop();
        if(st.empty())rs.push_back(n);
        else rs.push_back(st.top());
        st.push(i);
    }
    reverse(rs.begin(),rs.end());
    for(int i=0;i<n;i++){
        int ind=rs[i]-ls[i]-2;
        ans[ind]=max(ans[ind],a[i]);
    }
    for(int i=n-2;i>=0;i--){
        if(ans[i]<ans[i+1])ans[i]=ans[i+1];
    }
    return ans;
}