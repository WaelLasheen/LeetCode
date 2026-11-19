class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        if(nums.size() == 3) return 0;

        sort(nums.begin(),nums.end());
        int l=0 ,r= nums.size()-1;
        
        return min({nums[r-2]-nums[l] ,nums[r-1]-nums[l+1] ,nums[r]-nums[l+2]});
    }
};