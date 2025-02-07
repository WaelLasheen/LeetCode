class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<long,int> mp;    // color: freq
        unordered_map<int,int> ball;
        int s=queries.size();
        vector<int> res(s,0);
        int cnt=0;
        for(int i=0;i<s;i++){
            if(!ball[queries[i][0]]){
                ball[queries[i][0]] = queries[i][1];
                mp[queries[i][1]]++;
                if(mp[queries[i][1]] ==1){
                    cnt++;
                }
            }
            else{
                mp[ball[queries[i][0]]]--;
                if(!mp[ball[queries[i][0]]]){
                    cnt--;
                }
                ball[queries[i][0]] = queries[i][1];
                mp[queries[i][1]]++;
                if(mp[queries[i][1]] ==1){
                    cnt++;
                }
            }

            res[i]=cnt;
        }

        return res;
    }
};