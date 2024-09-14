class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_val=nums[0];
        for(int i=1;i<nums.size();i++){
            nums[i] = max(nums[i] ,nums[i] & nums[i-1]);

            max_val=max(max_val ,nums[i]);
        }
        int len=0 ,max_len=0;
        for(int i:nums){
            if(i==max_val){
                len++;
                max_len=max(max_len ,len);
            }else{
                len=0;
            }
        }
        return max_len;
    }
};