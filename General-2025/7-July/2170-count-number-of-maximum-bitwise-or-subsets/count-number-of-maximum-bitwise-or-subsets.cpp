class Solution {
public:
    map<int,int> orfr;
    int val=INT_MIN;
    void rec(vector<int>& nums ,int i ,int curr){
        if(i>=nums.size()){
            orfr[curr]++;
            val = max(val,curr);
            return;
        }
        rec(nums ,i+1 ,curr);
        rec(nums ,i+1 ,curr | nums[i]);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        rec(nums,0,0);
        return orfr[val];
    }
};