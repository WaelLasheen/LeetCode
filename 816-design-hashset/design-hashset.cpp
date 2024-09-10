class MyHashSet {
public:
    vector<bool> arr;
    MyHashSet() {
        
    }

    void handelSize(int key){
        if(key+1 > arr.size()){
            arr.resize(key+1 ,false);
        }
    }
    
    void add(int key) {
        handelSize(key);
        arr[key] = true;
    }
    
    void remove(int key) {
        handelSize(key);
        arr[key] = false;
    }
    
    bool contains(int key) {
        handelSize(key);
        return arr[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */