class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> v0,v1;
        int f0=0 ,f1=1;
        for(int i=0;i<words.size();i++){
            if(groups[i]==f0){
                v0.push_back(words[i]);
                f0 =!f0;
            }
            if(groups[i]==f1){
                v1.push_back(words[i]);
                f1 =!f1;
            }
        }

        return v0.size()>v1.size()? v0:v1;
    }
};