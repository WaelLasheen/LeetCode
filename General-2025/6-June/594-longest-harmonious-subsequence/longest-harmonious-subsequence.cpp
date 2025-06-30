class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        int res=0;
        for(int i:nums){
            mp[i]++;
        }

        for(auto [k,_]:mp){
            if(mp.count(k+1)){
                res = max(res,mp[k]+mp[k+1]);
            }
        }

        return res;
    }
};