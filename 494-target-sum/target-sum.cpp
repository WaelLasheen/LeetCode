class Solution {
public:
    int ans=0;
    void backtrack(vector<int>& nums, int t, int i){
        if(i==nums.size()){
            if(!t)ans++;
            return;
        }

        backtrack(nums ,t-nums[i] ,i+1);    // take nums[i] in positive
        backtrack(nums ,t+nums[i] ,i+1);    // take nums[i] in negative
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums,target,0);
        return ans;
    }
};