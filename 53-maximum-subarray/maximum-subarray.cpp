class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=INT_MIN ,sum=0;
        for(int i:nums){
            sum +=i;
            res = max(res,sum);
            if(sum<0) sum=0;
        }

        return res;
    }
};