class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.size()){
            return false;
        }

        vector<int> fr(26,0);
        for(char i:s){
            fr[i-'a']++;
        }

        int odd =0;
        for(int i:fr){
            odd += i&1;
        }

        return odd <= k;
    }
};