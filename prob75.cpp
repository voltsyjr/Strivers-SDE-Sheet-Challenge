#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    int *arr,tail,max_size;
    Stack(int capacity) {
        arr=new int[capacity];
        tail=0;
        max_size=capacity;
    }

    void push(int num) {
        if(tail!=max_size){
            arr[tail++]=num;
        }
    }

    int pop() {
        if(tail!=0)
            return arr[--tail];
        return -1;
    }
    
    int top() {
        return (tail!=0)?arr[tail-1]:-1;
    }
    
    int isEmpty() {
        return (tail==0)?1:0;
    }
    
    int isFull() {
        return (tail==max_size)?1:0;
    }
    
};