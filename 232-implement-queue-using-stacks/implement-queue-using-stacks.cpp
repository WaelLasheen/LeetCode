class MyQueue {
public:
    stack<int> add,del;
    int front=0;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(del.size()){
            add.push(del.top());
            del.pop();
        }
        add.push(x);
        if(add.size()==1){
            front=add.top();
        }
    }
    
    int pop() {
        while(add.size()){
            del.push(add.top());
            add.pop();
        }
        int n=del.top();
        del.pop();
        
        if(del.size()) front=del.top();

        return n;
    }
    
    int peek() {
        return front;
    }
    
    bool empty() {
        return add.empty() && del.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */