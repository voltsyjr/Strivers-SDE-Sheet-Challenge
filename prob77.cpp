#include<bits/stdc++.h>
class Stack {
	int size;
    queue<int>q1,q2;
   public:
    Stack() {
        size=0;
    }
    int getSize() {
        return size;
    }

    bool isEmpty() {
        return (size==0)?1:0;
    }

    void push(int element) {
        q2.push(element);
        while(!q1.empty()){
            int el=q1.front();
            q1.pop();
            q2.push(el);
        }
        swap(q1,q2);
        size++;
    }

    int pop() {
        if(q1.size()!=0){
            int el=q1.front();
            q1.pop();
            size--;
            return el;
        }
        return -1;
    }

    int top() {
        return (q1.size()!=0)?q1.front():-1; 
    }
};