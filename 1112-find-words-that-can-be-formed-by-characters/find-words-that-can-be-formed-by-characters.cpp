class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int> fr;
        for(const char i:chars) fr[i]++;
        int res=0;
        for(const string i:words){
            map<char,int> wfr;
            for(const char c:i){
                wfr[c]++;
                if(wfr[c] > fr[c]){
                    res -=i.size();
                    break;
                }
            }
            res +=i.size();
        }

        return res;
    }
};