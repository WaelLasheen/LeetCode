class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> v;
        int f=groups[0];
        for(int i=0;i<words.size();i++){
            if(groups[i]==f){
                v.push_back(words[i]);
                f =!f;
            }
        }

        return v;
    }
};