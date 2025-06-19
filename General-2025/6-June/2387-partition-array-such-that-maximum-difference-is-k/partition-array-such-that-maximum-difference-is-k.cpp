class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res=0 ,curr=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]-curr > k){
                res++;
                curr=nums[i];
            }
        }
        return res+1;
    }
};