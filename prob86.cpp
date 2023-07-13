#include <bits/stdc++.h> 
class minStack
{
	public:
	stack<long long>st;
	long long mini;
		minStack() {
			mini=INT_MAX;
		}
		void push(int num){
			long long val=num;
			if(st.empty()){
				st.push(val),mini=val;
				return;
			}
			if(val>=mini) st.push(val);
			else st.push(2*val*1LL-mini),mini=val;
		}
		int pop(){
			if(st.empty())return -1;
			long long el=st.top();
			st.pop();
			if(el<mini){
				long long t=mini;
				mini=2*mini-el;
				el=t;
			}
			if(st.empty())mini=INT_MAX;
			return el;
		}
		int top(){
			if(st.empty())return -1;
			long long el=st.top();
			if(el<mini)return mini;
			return el;
		}
		int getMin(){
			if(mini==INT_MAX)return -1;
			return mini;
		}
};