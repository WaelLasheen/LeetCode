class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> n(nums.begin(),nums.end());
        int sum=0,l=0;
        for(int i:n){
            if(i>0){
                sum +=i;
            }
            l=i;
        }

        return sum? sum:l;
    }
};