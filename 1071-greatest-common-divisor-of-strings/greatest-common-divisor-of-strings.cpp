class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len = __gcd(str1.size(),str2.size());

        string sub = str1.substr(0,len) ,sub1=sub,sub2=sub;
        for(int i=0;i<str2.size()/len-1;i++){
            sub2 += sub;
        }
        if(sub2 != str2) return "";

        for(int i=0;i<str1.size()/len-1;i++){
            sub1 += sub;
        }
        if(sub1 != str1) return "";

        return sub;
    }
};