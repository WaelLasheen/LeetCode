class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if(a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }

    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> fr;
        for (int i : nums) {
            fr[i]++;
        }
        
        vector<pair<int, int>> pr;
        for (auto i : fr) {
            pr.push_back(i);
        }
        sort(pr.begin(), pr.end(), cmp);
        vector<int> out;
        for (auto i : pr) {
            for(int j=0;j<i.second;j++){
                out.push_back(i.first);
            }
        }
        return out;
    }
};
