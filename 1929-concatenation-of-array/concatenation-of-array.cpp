class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int s=nums.size();
        nums.resize(2*s);
        for(int i=0;i<s;i++){
            nums[s+i]=nums[i];
        }
        return nums;
    }
};