class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int> mp;
        for(char i:word){
            mp[i]++;
        }

        vector<pair<int,char>> arr;
        for(auto [c,fr] :mp){
            arr.push_back({fr,c});
        }
        sort(arr.begin(),arr.end());

        int res=word.size();
        for(int i=0;i<arr.size();i++){
            int del=0;
            auto [ffr,_] = arr[i];     // fixed character & frequency
            for(int j=0;j<arr.size();j++){
                if(i==j){
                    continue;
                }

                auto [fr,_] = arr[j];
                if(ffr > fr){
                    del += fr;
                }
                else if (ffr+k < fr){
                    del += fr-ffr-k;
                }
            }
            res = min(res,del);
        }

        return res;
    }
};