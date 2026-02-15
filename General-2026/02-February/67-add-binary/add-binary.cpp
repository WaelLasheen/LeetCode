class Solution {
public:
    string addBinary(string a, string b) {
        int ita=a.size()-1 ,itb=b.size()-1 ,c=0;
        string res;
        while(ita>-1 || itb>-1){
            int bit = c;
            if(ita>-1) bit += a[ita--]-'0';
            if(itb>-1) bit += b[itb--]-'0';
            res += (bit&1) +'0';
            c = (bit&2)/2;
        }
        if(c) res += c+'0';

        reverse(res.begin(),res.end());
        return res;
    }
};