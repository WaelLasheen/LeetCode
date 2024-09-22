class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> fr;
        int s=0;
        for(int i:nums){
            fr[i]++;
            s=max(s,fr[i]);
        }

        vector<vector<int>> res(s);

        for(auto i:fr){
            while(i.second){
                i.second--;
                res[i.second].push_back(i.first);
            }
        }

        return res;
    }
};