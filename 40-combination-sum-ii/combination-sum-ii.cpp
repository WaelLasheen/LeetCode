class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        set<pair<int,vector<int>>> con;
        vector<int> em;
        con.insert({0,em});
        for(int i:candidates){
            set<pair<int,vector<int>>> inner = con;
            for(pair<int,vector<int>> j: con){
                vector<int> arr = j.second;
                if(j.first+i <= target){
                    arr.push_back(i);
                    inner.insert({j.first+i,arr});
                }
            }
            con = inner;
        }
        vector<vector<int>> res;
        for(pair<int,vector<int>> i: con){
            if(i.first==target){
                res.push_back(i.second);
            }
        }

        return res;
    }
};