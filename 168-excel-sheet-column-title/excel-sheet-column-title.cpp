class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res="";
        while(columnNumber){
            if(columnNumber % 26){
                res += string(1,char(columnNumber % 26 -1 +'A'));
                columnNumber /=26;
            }else{
                res += "Z";
                columnNumber =columnNumber /26 -1;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};