class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            int cnt=2 , sum=nums[i]+1;
            for(int j=2;j*j<=nums[i];j++){
                if(j*j == nums[i]){
                    cnt++;
                    sum += j;
                }
                else if(!(nums[i]%j)){
                    cnt +=2;
                    sum += nums[i]/j + j;
                }
            }

            if(cnt==4){
                res +=sum;
            }
        }

        return res;
    }
};