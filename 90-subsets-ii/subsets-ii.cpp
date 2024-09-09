class Solution {
public:
    vector<vector<int>> subSets;

    void backtrack(vector<int>& nums ,vector<int>& sub ,int it){
        if(it >= nums.size()){
            vector<int> con=sub;
            sort(sub.begin(),sub.end());
            if(find(subSets.begin(),subSets.end(),sub) == subSets.end()){
                subSets.push_back(sub);
            }
            sub = con;
            return;
        }

        backtrack(nums ,sub ,it+1); 
        sub.push_back(nums[it]);       
        backtrack(nums ,sub ,it+1);
        sub.pop_back();       
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub;
        backtrack(nums ,sub ,0);

        return subSets;
    }
};