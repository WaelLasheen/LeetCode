class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n= nums.size();
        int res=0;
        for(int i=1;i*i<=n;i++){
            if(!(n%i)){
                if(i*i==n){
                    res += nums[i-1] * nums[i-1];
                } else{
                    res += nums[i-1] * nums[i-1];
                    int j = n/i;
                    res += nums[j-1] * nums[j-1];
                }
            }
        }

        return res;
    }
};