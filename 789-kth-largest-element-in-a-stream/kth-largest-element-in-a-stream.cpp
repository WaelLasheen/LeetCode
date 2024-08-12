class KthLargest {
public:
    vector<int> largek;
    KthLargest(int k, vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size() < k){
            largek.push_back(INT_MIN);
            for(int i=nums.size()-k+1;i<nums.size();i++){
                largek.push_back(nums[i]);
            }
            return;
        }
        for(int i=nums.size()-k;i<nums.size();i++){
            largek.push_back(nums[i]);
        }
    }
    
    int add(int val) {
        if(!largek.size()){
            largek.push_back(val);
        }
        else if(val > largek[0]){
            largek[0]= val;
            sort(largek.begin(),largek.end());
        }

        return largek[0];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */