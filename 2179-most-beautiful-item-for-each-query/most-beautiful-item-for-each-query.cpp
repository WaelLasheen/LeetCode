class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int,int> mp;
        for(vector<int> i:items){
            mp[i[0]] = max(mp[i[0]] ,i[1]);
        }

        vector<int> keys(mp.size()+1,0);
        int  it=1;
        for(auto i:mp){
            keys[it] = i.first;
            mp[keys[it]] = max(mp[keys[it]] ,mp[keys[it-1]]);
            it++;
        }

        vector<int> res(queries.size());
        it=0;
        for(int q:queries){
            int i = upper_bound(keys.begin(),keys.end(),q)-keys.begin()-1;
            res[it] = mp[keys[i]];
            it++;
        }

        return res;
    }
};