class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size()==1) return true;
        for(int i=0;i<nums.size()-1;i++){
            int b1=nums[i]%2 ,b2=nums[i+1]%2;
            if(!(b1^b2)) return false;
        }
        return true;
    }
};