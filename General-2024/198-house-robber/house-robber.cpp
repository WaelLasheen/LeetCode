class Solution {
public:
    int rob(vector<int>& nums) {
        int s = nums.size();
        if(s==1) return nums[0];
        else if(s==2) return max(nums[0],nums[1]);
        else if(s==3) return max(nums[0]+nums[2],nums[1]);
        nums[2] += nums[0];    // don't miss this \U0001f609
        for(int i=3;i<s;i++){
            nums[i] += max(nums[i-2],nums[i-3]);
        }
        return max(nums[s-1],nums[s-2]);
    }
};