class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int i=0;
        for(int n:nums){
            if(n==target) ans.push_back(i);
            i++;
        }
        return ans;
    }
};