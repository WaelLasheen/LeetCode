class Solution {
public:
    vector<vector<int>> res;

    void solve(vector<int>& candidates, int target, int index, vector<int>& sub) {
        if (target == 0) {
            res.push_back(sub);
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i-1]) continue;
            // Early termination
            if (candidates[i] > target) break;
            
            sub.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i + 1, sub);
            sub.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> sub;
        solve(candidates, target, 0, sub);
        return res;
    }
};
