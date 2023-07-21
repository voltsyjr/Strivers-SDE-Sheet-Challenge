#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<int>adj[n+1];
  vector<int>inDegree(n+1,0);
  for(auto it:edges){
    adj[it.first].push_back(it.second);
    inDegree[it.second]++;
  }
  queue<int>q;
  for(int i=1;i<=n;i++)if(inDegree[i]==0)q.push(i);
  int removableNodes=0;
  while(!q.empty()){
    int node=q.front();
    q.pop();
    removableNodes++;
    for(auto it:adj[node]){
      inDegree[it]--;
      if(inDegree[it]==0)q.push(it);
    }
  }
  if(removableNodes==n)return 0;
  return 1;
}