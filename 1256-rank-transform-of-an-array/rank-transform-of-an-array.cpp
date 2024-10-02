class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mp;
        for(int i:arr) mp[i];
        int it=1;
        for(auto i:mp){
            mp[i.first] =it;
            it++;
        }
        for(int& i:arr){
            i = mp[i];
        }

        return arr;
    }
};