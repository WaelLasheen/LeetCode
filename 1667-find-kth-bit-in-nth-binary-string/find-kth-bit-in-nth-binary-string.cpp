class Solution {
public:
    string reverseInvert(string& s){
        string res="";
        for(int i=s.size()-1;i>-1;i--){
            res += (s[i]=='0'? "1":"0");
        }
        return res;
    }

    char findKthBit(int n, int k) {
        string s="0";
        for(int i=1;i<n;i++){
            s = s+"1"+reverseInvert(s);
        }

        return s[k-1];
    }
};