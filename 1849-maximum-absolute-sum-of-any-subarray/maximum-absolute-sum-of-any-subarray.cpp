class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mx=INT_MIN ,mn=INT_MAX ,currMX=0 ,currMN;
        for(int i:nums){
            currMX=max(i,currMX+i);
            mx=max(mx,currMX);

            currMN=min(i,currMN+i);
            mn=min(mn,currMN);
        }

        return max(mx ,abs(mn));
    }
};