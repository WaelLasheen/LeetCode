class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res=0;
        for(string s:details){
            if(s[11] >'6' || (s[11]=='6' && s[12] !='0')) res++;
        }
        return res;
    }
};