class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // handel s
        for(int i=0;i<s.size();){
            if(s[i]=='#'){
                s.erase(s.begin()+i);  // remove #
                if(i){
                    i--;
                    s.erase(s.begin()+i);// remove char
                }
            } else{
                i++;
            }
        }
        // handel t
        for(int i=0;i<t.size();){
            if(t[i]=='#'){
                t.erase(t.begin()+i);  // remove #
                if(i){
                    i--;
                    t.erase(t.begin()+i);// remove char
                }
            } else{
                i++;
            }
        }

        return s==t;
    }
};