class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans="0000000000000000";
        int s = nums.size();
        ans = ans.substr(0,s);
        // try zero maybe it work
        if(find(nums.begin(),nums.end(),ans) == nums.end()) return ans;
        for(int i=0;i<s;i++){
            ans[i]='1';
            if(find(nums.begin(),nums.end(),ans) == nums.end())
                return ans;
            ans[i]='0';
        }
        return ans;
    }
};