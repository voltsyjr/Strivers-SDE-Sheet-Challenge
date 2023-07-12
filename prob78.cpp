class Queue {
    stack<int>input,output;
    int size;
    public:
    Queue() {
        size=0;
    }

    void enQueue(int val) {
        size++;
        input.push(val);
    }

    int deQueue() {
        if(size==0)
            return -1;
        if(output.empty()){
            while(!input.empty()){
                int el=input.top();
                input.pop();
                output.push(el);
            }
        }
        size--;
        int el=output.top();
        output.pop();
        return el;
    }

    int peek() {
        if(size==0)
            return -1;
        if(output.empty()){
            while(!input.empty()){
                int el=input.top();
                input.pop();
                output.push(el);
            }
        }
        return output.top();
    }

    bool isEmpty() {
        return (size==0)?1:0;
    }
};