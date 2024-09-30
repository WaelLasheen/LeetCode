class CustomStack {
public:
    vector<int> sta;
    int ms ,it=-1;
    CustomStack(int maxSize) {
        ms=maxSize;
        sta.resize(ms,0);
    }
    
    void push(int x) {
        if(it+1<ms){
            it++;
            sta[it]=x;
        }
    }
    
    int pop() {
        if(it !=-1){
            int top=sta[it];
            it--;
            return top;
        }

        return -1;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(it+1,k);i++){
            sta[i] +=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */