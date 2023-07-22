#include <bits/stdc++.h> 
class DisjointSet{
public:
	vector<int>parent,size;
	DisjointSet(int n){
		parent.resize(n+1,0);
		size.resize(n+1,1);
		for(int i=0;i<=n;i++)parent[i]=i;
	}
	int findupar(int u){
		if(parent[u]==u)return u;
		return parent[u]=findupar(parent[u]);
	}
	void unionBySize(int u,int v){
		int upar_u=findupar(u),upar_v=findupar(v);
		if(upar_u==upar_v)return;
		if(size[upar_u]>size[upar_v]){
			parent[upar_v]=upar_u;
			size[upar_u]+=size[upar_v];
		}else{
			parent[upar_u]=upar_v;
			size[upar_v]+=size[upar_u];
		}
	}
};
bool comp(vector<int>&a,vector<int>&b){
	if(a[2]<=b[2])return true;
	return false;
}
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	DisjointSet ds(n+1);
	sort(graph.begin(),graph.end(),comp);
	vector<vector<int>>MST;
	int ans=0;
	for(auto it:graph){
		if(ds.findupar(it[0])!=ds.findupar(it[1])){
			ds.unionBySize(it[0],it[1]);
			MST.push_back({it[0],it[1],it[2]});
			ans+=it[2];
		}
	}
	return ans;
}