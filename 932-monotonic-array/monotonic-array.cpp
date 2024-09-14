class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int pos=0 ,neg=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]-nums[i] >0){
                pos++;
            }else if(nums[i-1]-nums[i] <0){
                neg++;
            }
        }

        if((!neg && !pos) || (!neg && pos) || (neg && !pos)){
            return true;
        }
        return false;
    }
};