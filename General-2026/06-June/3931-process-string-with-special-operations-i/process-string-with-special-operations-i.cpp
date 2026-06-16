class Solution {
public:
    string processStr(string s) {
        string res="";
        for(char i:s){
            if(i=='*' && res.size()) res.pop_back();
            else if(i=='#') res +=res;
            else if(i=='%') reverse(res.begin(),res.end());
            else if(isalpha(i)) res +=i;
        }

        return res;
    }
};