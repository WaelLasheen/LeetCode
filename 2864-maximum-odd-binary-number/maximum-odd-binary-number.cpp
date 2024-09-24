class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int l=0;
        while(s[l]=='1') l++;
        for(int i=l+1;i<s.size();i++){
            if(s[i]=='1'){
                swap(s[i],s[l]);
                l++;
            }
        }
        swap(s[l-1],s[s.size()-1]);
        return s;
    }
};