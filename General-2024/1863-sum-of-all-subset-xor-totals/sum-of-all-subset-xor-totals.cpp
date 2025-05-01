class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int s = nums.size() ,poss= 1<<s ,sum=0;

        for(int i=1;i<poss;i++){
            int it=0 ,num=i ,res=0;
            while(num){
                res ^=nums[it] * (num&1);
                num >>=1;
                it++;
            }
            sum +=res;
        }

        return sum;
    }
};