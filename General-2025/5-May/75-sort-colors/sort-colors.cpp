class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> mp(3,0);
        for(int i:nums){
            mp[i]++;
        }

        int it=0;
        for(int i=0;i<nums.size();i++){
            while(!mp[it] && it!=3){
                it++;
            }
            
            if(mp[it]){
                nums[i]=it;
                mp[it]--;
            }
        }
    }
};