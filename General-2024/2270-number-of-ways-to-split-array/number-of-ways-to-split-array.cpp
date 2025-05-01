class Solution {
public:
    int waysToSplitArray(vector<int>& arr) {
        vector<long> nums(arr.begin(),arr.end());
        for(int i=1;i<nums.size();i++){
            nums[i] +=nums[i-1];
        }

        int it = nums.size()-1;
        int res=0;
        for(int i=0;i<it;i++){
            if(2*nums[i] >= nums[it]){
                res++;
            }
        }

        return res;
    }
};