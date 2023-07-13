class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>ls,rs;
        stack<int>st;
        //find left next smaller
        st.push(0);
        ls.push_back(0);
        int n=heights.size();
        for(int i=1;i<n;i++){
            while(!st.empty() and heights[st.top()]>=heights[i])st.pop();
            if(st.empty()) ls.push_back(0);
            else ls.push_back(st.top()+1);
            st.push(i);
        }
        while(!st.empty())st.pop();
        //find right next smaller
        st.push(n-1);
        rs.push_back(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() and heights[st.top()]>=heights[i])st.pop();
            if(st.empty()) rs.push_back(n-1);
            else rs.push_back(st.top()-1);
            st.push(i);
        }
        reverse(rs.begin(),rs.end());
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,((rs[i]-ls[i]+1)*heights[i]));
        }
        return ans;
    }
};