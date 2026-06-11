class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int s = nums.size();
        for(int i=1;i<s;i++){
            nums[i] += nums[i-1];
        }

        vector<int> res(s,nums.back()-nums[0]);
        for(int i=1;i<s;i++){
            int right = nums.back()-nums[i];
            res[i] = abs(right - nums[i-1]);
        }

        return res;
    }
};

// 10 14 22 25