class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0,p=0,sum=0;
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            while(s.find(nums[i]) !=s.end()){
                s.erase(nums[p]);
                sum -=nums[p];
                p++;
            }
            s.insert(nums[i]);
            sum +=nums[i];
            ans=max(ans,sum);
        }
        return ans;
    }
};