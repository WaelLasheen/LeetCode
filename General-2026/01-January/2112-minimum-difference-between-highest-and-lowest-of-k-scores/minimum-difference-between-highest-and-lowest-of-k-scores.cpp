class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size() ,l=0,r=k-1 ,diff=INT_MAX;
        sort(nums.begin(),nums.end());
        while(r<n){
            diff = min(diff,nums[r++]-nums[l++]);
        }

        return diff;
    }
};