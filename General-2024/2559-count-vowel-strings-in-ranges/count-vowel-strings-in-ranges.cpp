class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int s = words.size();
        vector<int> pref(s+1,0);
        for(int i=0;i<s;i++){
            if(isVowel(words[i][0]) && isVowel(words[i].back())){
                pref[i+1]++;
            }
            pref[i+1] +=pref[i];
        }
        int t = queries.size();
        vector<int> res(t);
        for(int i=0;i<t;i++){
            int l = queries[i][0] ,r=queries[i][1];
            res[i] = pref[r+1] - pref[l];
        }
        
        return res;
    }
private:
    bool isVowel(char& s){
        return s=='a' || s=='e' || s=='i' || s=='o' ||s=='u';
    }
};