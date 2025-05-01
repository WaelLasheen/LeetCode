class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> fr;
        for (int i : nums) {
            fr[i]++;
        }
        vector<pair<int, int>> pr;
        for (auto i:fr) {
            pr.push_back({i.second,-i.first});
        }
        sort(pr.begin(), pr.end());
        int it=0;
        for (auto i : pr) {
            while(i.first--){
                nums[it++]=-i.second;
            }
        }
        return nums;
    }
};

