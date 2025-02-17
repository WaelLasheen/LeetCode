class Solution {
public:
    unordered_set<string> s;

    void solve(string& curr ,vector<int>& mp ,int mx){
        if(!mx){
            s.insert(curr);
            return;
        }

        s.insert(curr);

        for(int i=0;i<26;i++){
            if(mp[i]){
                mp[i]--;
                curr += char(i+'A');
                solve(curr,mp,mx-1);
                curr.pop_back();
                mp[i]++;
            }
        }
    }

    int numTilePossibilities(string tiles) {
        vector<int> mp(26,0);
        for(char i:tiles){
            mp[i-'A']++;
        }
        string curr="";
        solve(curr,mp,tiles.size());

        return s.size()-1;      //-1 to remove empty probabilty ""
    }
};