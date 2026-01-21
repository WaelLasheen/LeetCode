class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,-1);

        for(int i=0;i<n;i++){
            if(nums[i]==2) continue;
            int num = nums[i] ,rem=0;
            while(num){
                bool b = num&1;
                if(b){
                    rem = rem*2+1;
                    num /=2;
                } 
                else{
                    break;
                }
            }
            if(!num){
                res[i] = rem/2;
            } else{
                res[i] = nums[i] - rem + rem/2;
            }
        }

        return res;
    }
};