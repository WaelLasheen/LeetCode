class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int res = 0 ,len = nums.size();
        for(int i=0;i<len;i++){
            int cnt = 0;
            for(int j=i;j<len;j++){
                if(nums[j] == target) cnt++;
                if(cnt > (j-i+1)/2) res++;
            }
        }

        return res;
    }
};