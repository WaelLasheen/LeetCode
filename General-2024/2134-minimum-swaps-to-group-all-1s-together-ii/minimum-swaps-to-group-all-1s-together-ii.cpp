class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int s=nums.size();
        int ones=0;
        for(int i:nums){
            ones +=i;
        }
        int wind1=0;
        for(int i=0;i<ones;i++){
            wind1+= nums[i];
        }

        int maxOnes=wind1;

        for(int i=ones;i<2*s;i++){
            wind1 = wind1 + nums[i%s]-nums[(i-ones)%s];
            maxOnes=max(maxOnes,wind1);
        }
        return ones-maxOnes;
    }
};