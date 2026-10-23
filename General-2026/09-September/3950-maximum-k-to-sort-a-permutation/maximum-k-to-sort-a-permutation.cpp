class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int len = nums.size();
        int res = -1;
        for(int i=0;i<len;i++){
            if(nums[i] !=i){
                if(res ==-1){
                    res = nums[i];
                } else{
                    res = res & nums[i];
                }
            }
        }

        return res == -1? 0 : res;
    }
};