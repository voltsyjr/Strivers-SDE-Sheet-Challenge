#include <bits/stdc++.h> 
struct temp{
	int left,right,height;
	temp(int l,int r,int h){
		left=l,right=r,height=h;
	}
};
int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	vector<int>pos(N+1,0);
	for(int i=0;i<N;i++){
		pos[inorder[i]]=i;
	}
	queue<temp>q;
	q.push({0,N-1,0});
	int maxi=0;
	for(int i=0;i<N;i++){
		int cur=levelOrder[i];
		int curPos=pos[cur];
		auto node=q.front();
		q.pop();
		int left=node.left,right=node.right,height=node.height;
		maxi=max(maxi,height);
		if(curPos>left){
			q.push({left,curPos-1,height+1});
		}
		if(curPos<right){
			q.push({curPos+1,right,height+1});
		}
	}
	return maxi;
}