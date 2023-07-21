#include<bits/stdc++.h>
void dfsSort(int node,vector<int>adj[],stack<int>&s,vector<int>&vis){
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(vis[it]==0)dfsSort(it,adj,s,vis);
	    }
	    s.push(node);
	    return;
	}
vector<vector<int>> stronglyConnectedComponents(int V, vector<vector<int>> &edges)
{
        stack<int>s;
        vector<int>vis(V,0);
        vector<int>adj[V];
        for(auto it:edges) adj[it[0]].push_back(it[1]);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfsSort(i,adj,s,vis);
            }
        }
        vector<int>rev[V];
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                rev[it].push_back(i);
            }
        }
        for(int i=0;i<V;i++)vis[i]=0;
        vector<vector<int>>ConComList;
        while(!s.empty()){
            int node=s.top();
            s.pop();
            if(vis[node]==0){
                vector<int>temp;
                stack<int>st;
                dfsSort(node,rev,st,vis);
                while(!st.empty()){
                    temp.push_back(st.top());
                    st.pop();
                }
                ConComList.push_back(temp);
            }
        }
        return ConComList;
}