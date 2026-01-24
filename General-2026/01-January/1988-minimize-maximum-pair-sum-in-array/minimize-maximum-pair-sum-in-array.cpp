class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int res=INT_MIN ,n=nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n/2;i++){
           res = max(res,nums[i]+nums[n-i-1]);
        }

        return res;
    }
};

// [4,1,5,1,2,5,1,5,5,4]
// [1,1,1,2,4,4,5,5,5,5]