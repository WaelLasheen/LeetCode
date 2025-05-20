class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> pref(n+1,0);
        for(int i=0;i<queries.size();i++){
            pref[queries[i][0]]++;
            pref[queries[i][1]+1]--;
        }

        for(int i=0;i<n;i++){
            if(i){
                pref[i] +=pref[i-1];
            }

            if(pref[i] < nums[i]){
                return false;
            }
        }

        return true;
    }
};