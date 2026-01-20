class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len,-1);
        for(int i=0;i<len;i++){
            for(int j=1;j<=nums[i];j++){
                if(((j)|(j+1)) == nums[i]){
                    ans[i]=j;
                    break;
                }
            }
        }

        return ans;
    }
};