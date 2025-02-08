class NumberContainers {
public:
    unordered_map<long,priority_queue<long,vector<long>,greater<long>>> mp;  // val:[indexs]
    unordered_map<long,long> ind;   // index:val

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        ind[index]=number;
        mp[number].push(index);
    }
    
    int find(int number) {
        // if min ind not arow to
        while(mp[number].size()){
            int mn=mp[number].top();    // min index -> val
            if(ind[mn]==number){
                return mn;
            }
            mp[number].pop();
        }

        // if queue empty -> no answer
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */