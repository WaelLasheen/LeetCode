class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(!k) return false;
        unordered_map<int,int> num_it;
        for(int i=0;i<nums.size();i++){
            if(num_it.find(nums[i]) != num_it.end() && i-num_it[nums[i]] <= k){
                return true;
            }

            num_it[nums[i]]=i;
        }


        return false;
    }
};