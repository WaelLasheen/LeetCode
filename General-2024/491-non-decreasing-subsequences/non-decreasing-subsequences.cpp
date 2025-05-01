class Solution {
public:
    set<vector<int>> res;

    void backtrack(vector<int>& nums ,vector<int>& sub ,int i){
        if(i==nums.size()){
            if(sub.size() >1)
                res.insert(sub);
            return;
        }

        if(!(sub.size()) || sub[sub.size()-1] <=nums[i]){
            sub.push_back(nums[i]);
            backtrack(nums ,sub ,i+1);
            sub.pop_back();
        }
        backtrack(nums ,sub ,i+1);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> sub;
        backtrack(nums,sub,0);
        vector<vector<int>> ans (res.begin(),res.end());
        return ans;
    }
};