class Solution {
public:
    int sumCounts(vector<int>& nums) {
        unordered_set<int> dis;
        int len = nums.size();
        int res = 0;
        for(int i=0;i<len;i++){
            for(int j=i;j<len;j++){
                dis.insert(nums[j]);
                res += dis.size() * dis.size();
            }
            dis.clear();
        }


        return res;
    }
};