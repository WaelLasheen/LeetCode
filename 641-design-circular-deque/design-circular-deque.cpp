class MyCircularDeque {
public:
    int s ,it=-1;
    list<int> deque;
    MyCircularDeque(int k) {
        s=k;
    }
    
    bool insertFront(int value) {
        if(it+1 <s){
            deque.push_front(value);
            it++;
            return true;
        }

        return false;
    }
    
    bool insertLast(int value) {
        if(it+1 <s){
            deque.push_back(value);
            it++;
            return true;
        }

        return false;
    }
    
    bool deleteFront() {
        if(it>-1){
            deque.pop_front();
            it--;
            return true;
        }
        
        return false;
    }
    
    bool deleteLast() {
        if(it>-1){
            deque.pop_back();
            it--;
            return true;
        }
        
        return false;
    }
    
    int getFront() {
        if(it==-1) return -1;
        return deque.front();
    }
    
    int getRear() {
        if(it==-1) return -1;

        return deque.back();
    }
    
    bool isEmpty() {
        return it==-1;
    }
    
    bool isFull() {
        return it+1==s;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */