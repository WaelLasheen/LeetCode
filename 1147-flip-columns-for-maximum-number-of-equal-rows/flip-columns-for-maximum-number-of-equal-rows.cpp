class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int len = matrix[0].size();
        unordered_map<string,int> fr;
        int res=0;
        for(vector<int>& arr:matrix){
            string key = string(len,'0'), fkey=key;
            for(int i=0;i<len;i++){
                key[i] += arr[i];
                fkey[i] += (arr[i]+1)&1;
            }
            fr[key]++;
            fr[fkey]++;
            res=max({res,fr[key],fr[fkey]});
        }

        return res;
    }
};