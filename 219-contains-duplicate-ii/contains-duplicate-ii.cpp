class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(!k) return false;
        map<int,vector<int>> num_it;
        for(int i=0;i<nums.size();i++){
            num_it[nums[i]].push_back(i);
        }

        for(auto it:num_it){
            if(it.second.size()>1){
                for(int i=0;i<it.second.size()-1;i++){
                    if(it.second[i+1] - it.second[i] <=k){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};