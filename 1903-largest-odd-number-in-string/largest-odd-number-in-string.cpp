class Solution {
public:
    string largestOddNumber(string num) {
        int l=num.size()-1;
        while(l>-1){
            if((num[l]-'0')&1){
                return num.substr(0,l+1);
            }
            l--;
        }

        return "";
    }
};