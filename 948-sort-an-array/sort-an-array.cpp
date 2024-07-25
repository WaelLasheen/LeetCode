class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int,int>fr;
        for(int i:nums) fr[i]++;
        nums.clear();
        for(auto i:fr){
            while(i.second--){
                nums.push_back(i.first);
            }
        }
        return nums;
    }
};