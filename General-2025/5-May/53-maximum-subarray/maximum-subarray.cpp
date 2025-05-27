class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0] ,sum=0 ,mx=nums[0];    // result-> max sum ,sum-> current sum that is greater than 0 ,mx-> max element to handel all negative case
        for(int i:nums){
            sum +=i;
            if(sum>0){
                res=max(res,sum);
            } else{
                sum=0;
            }

            mx=max(mx,i);
        }

        return max(res,mx);
    }
};