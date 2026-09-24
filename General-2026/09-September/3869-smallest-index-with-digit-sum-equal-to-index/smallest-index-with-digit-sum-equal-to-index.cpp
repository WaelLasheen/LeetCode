class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i == digitsSum(nums[i])){
                return i;
            }
        }

        return -1;
    }
private:
    int digitsSum(int num){
        int res=0;
        while(num){
            res += num%10;
            num /=10;
        }

        return res;
    }
};