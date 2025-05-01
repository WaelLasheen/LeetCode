class MyHashMap {
public:
    vector<int> arr;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        if(arr.size()<key+1){
            arr.resize(key+1 ,-1);
        }
        arr[key]=value;
    }
    
    int get(int key) {
        if(arr.size()<=key) return -1;

        return arr[key];
    }
    
    void remove(int key) {
        if(arr.size()>key){
            arr[key]=-1;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */