class Solution {
public:
    int maxScore(string s) {
        int ones=0;
        for(const char i:s){
            if(i=='1') ones++;
        }

        int res=0 ,zeros=0;
        for(int i=0;i<s.size()-1;i++){
            s[i]=='1'? ones-- :zeros++;
            res=max(res,ones+zeros);
        }

        return res;
    }
};