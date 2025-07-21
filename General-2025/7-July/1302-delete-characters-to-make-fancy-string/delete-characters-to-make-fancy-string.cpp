class Solution {
public:
    string makeFancyString(string s) {
        int len=s.size();
        if(len<3) return s;
        
        string res="";
        for(int i=0;i<len-2;i++){
            if(s[i] !=s[i+1] || s[i+1] !=s[i+2]){
                res +=s[i];
            }
        }
        res += s[len-2];
        res += s[len-1];

        return res;
    }
};