class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,int> mp;
        map<char,vector<int>> it; //char : [it1,it2,it3,...]
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            it[s[i]].push_back(i);
        }
        int res=0;
        for(char i='a';i<='z';i++){
            if(mp[i]>1){
                for(char j='a';j<='z';j++){
                    for(int k:it[j]){
                        if(k > it[i][0] && k < it[i].back()){
                            res++;
                            break;
                        }
                    }
                }
            }
        }

        return res;
    }
};