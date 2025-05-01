class Solution {
public:
    int minimumPushes(string word) {
        vector<int> fr(26,0);
        for(char i:word){
            fr[i-'a']++;
        }

        sort(fr.rbegin(),fr.rend());

        int res=0;
        for(int i=0;i<26;i++){
            res += (fr[i]*(i/8 +1));
        }

        return res;
    }
};