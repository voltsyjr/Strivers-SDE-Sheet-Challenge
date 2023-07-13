#include <bits/stdc++.h> 
priority_queue<int,vector<int>,greater<int>>mnheap;
void sortStack(stack<int> &stack)
{
	if(stack.empty())return;
	mnheap.push(stack.top());
	stack.pop();
	sortStack(stack);
	stack.push(mnheap.top());
	mnheap.pop();
	return;
}