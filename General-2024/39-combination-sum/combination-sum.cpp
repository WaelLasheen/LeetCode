class Solution {
public:
    set<vector<int>> res;
    void dfs(vector<int>&arr ,int a ,vector<int>& sub ,int i){
        if(i>=arr.size() || a<0) return;
        if(a==0) {res.insert(sub); return;}
        dfs(arr,a,sub,i+1);
        sub.push_back(arr[i]);
        dfs(arr,a-arr[i],sub,i+1);
        dfs(arr,a-arr[i],sub,i);
        sub.pop_back();   ///////////////
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sub;
        dfs(candidates,target,sub,0);
        vector<vector<int>>ans;
        for(auto i:res) ans.push_back(i);
        return ans;
    }
};

