class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int len = nums.size();
        int res = -1;
        for(int i=0;i<len;i++){
            if(nums[i] !=i){
                int n1 = nums[i];
                int n2 = nums[n1];
                swap(nums[i],nums[n1]);
                if(res ==-1){
                    res = n1 & n2;
                } else{
                    res = res & n1 & n2;
                }
            }
        }

        return res == -1? 0 : res;
    }
};