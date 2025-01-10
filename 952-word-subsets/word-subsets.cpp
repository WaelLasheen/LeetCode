class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> chars(26,0);
        for(string i:words2){
            vector<int> fr(26,0);
            for(char c:i){
                fr[c-'a']++;
            }

            for(int it=0;it<26;it++){
                chars[it] = max(chars[it],fr[it]);
            }
        }
        
        vector<string> res;
        for(string i:words1){
            vector<int> mp(26,0);
            for(char c:i){
                mp[c-'a']++;
            }

            bool f=true;
            for(int it=0;it<26;it++){
                if(chars[it] > mp[it]){
                    f=false;
                    break;
                }
            }
            if(f){
                res.push_back(i);
            }
        }

        return res;
    }
};