class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] >= i+1){
                res++;
            } else{
                if(res == nums[i]) return -1;
                break;
            }
        }

        return !res? -1 : res;
    }
};