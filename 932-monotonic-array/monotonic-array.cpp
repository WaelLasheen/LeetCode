class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int> copy=nums;
        sort(copy.begin(),copy.end());
        if(copy==nums) return true;
        sort(copy.rbegin(),copy.rend());
        if(copy==nums) return true;
        return false;
    }
};