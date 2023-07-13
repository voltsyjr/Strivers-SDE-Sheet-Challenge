#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &prices) {
    stack<int>st;
    vector<int>lg;
    lg.push_back(0);
    st.push(0);
    for(int i=1;i<prices.size();i++){
        while(!st.empty() and prices[st.top()]<=prices[i])st.pop();
        if(st.empty())lg.push_back(0);
        else lg.push_back(st.top()+1);
        st.push(i);
    }
    for(int i=0;i<prices.size();i++){
        lg[i]=i-lg[i]+1;
    }
    return lg;
}
