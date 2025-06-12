class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int res= abs(nums[0]-nums.back());

        for(int i=0;i<nums.size()-1;i++){
            res= max(res,abs(nums[i]- nums[i+1]));
        }

        return res;
    }
};