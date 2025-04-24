class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int res=0;
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }

        int s= mp.size() ,cnt=0 ,l=0 ,r=0;
        mp.clear();

        while(r<nums.size()){
            if(!mp[nums[r]]){
                cnt++;
            }
            mp[nums[r]]++;

            while(cnt==s){
                res += nums.size()-r;
                mp[nums[l]]--;
                if(!mp[nums[l]]){
                    cnt--;
                }
                l++;
            }

            r++;
        }

        return res;
    }
};