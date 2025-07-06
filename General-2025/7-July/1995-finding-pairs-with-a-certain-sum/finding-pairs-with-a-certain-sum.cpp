class FindSumPairs {
public:
    unordered_map<int,int> mp1 ,mp2;
    vector<int> arr;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int i:nums1) mp1[i]++;
        for(int i:nums2) mp2[i]++;
        arr=nums2;
    }
    
    void add(int index, int val) {
        mp2[arr[index]]--;
        if(!mp2[arr[index]]){
            mp2.erase(arr[index]);
        }

        arr[index] +=val;
        mp2[arr[index]]++;
    }
    
    int count(int tot) {
        int res=0;
        for(auto [k,v]:mp1){
            if(mp2.count(tot-k)){
                res += v*mp2[tot-k];
            }
        }

        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */