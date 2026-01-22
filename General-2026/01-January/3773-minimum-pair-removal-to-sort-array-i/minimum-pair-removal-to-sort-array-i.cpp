class Solution {
public:
    void process(vector<int>& nums){
        int mn= INT_MAX ,it=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]+nums[i+1] < mn){
                mn = nums[i]+nums[i+1];
                it = i;
            }
        }
        nums[it] = mn;
        nums.erase(nums.begin()+it+1);
    }

    int minimumPairRemoval(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] > nums[i+1]){
                res++;
                process(nums);
                i=-1;
            }
        }

        return res;
    }
};