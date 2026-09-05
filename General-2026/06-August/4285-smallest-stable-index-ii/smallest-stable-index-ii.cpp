class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int len=nums.size();

        vector<int> mx(len,nums[0]) ,mn(len,nums.back());
        for(int i=1;i<len;i++){
            int j=len-i-1;
            mx[i] = max(mx[i-1],nums[i]);
            mn[j] = min(mn[j+1],nums[j]);
        }

        for(int i=0;i<len;i++){
            if(mx[i]-mn[i] <= k){
                return i;
            }
        }

        return -1;
    }
};