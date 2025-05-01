class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>fr1,fr2;
        for(int i:nums1) fr1[i]++;
        for(int i:nums2) fr2[i]++;
        vector<int>v1,v2;
        for(auto i:fr1){
            if(!fr2[i.first]) v1.push_back(i.first);
        }
        for(auto i:fr2){
            if(!fr1[i.first]) v2.push_back(i.first);
        }
        return {v1,v2};
    }
};