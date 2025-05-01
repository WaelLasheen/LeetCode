class Solution {
public:
    string minWindow(string s, string t) {
        string sub=s.substr(0,t.size());
        unordered_map<char,int> frt;
        for(char i:t) frt[i]++;
        unordered_map<char,int> window;
        for(char i:sub) window[i]++;
        if(frt == window) return sub;

        string ans="";
        for(int i=t.size();i<s.size();i++){
            window[s[i]]++;
            sub +=s[i];
            bool is=true;
            for(auto c:frt){
                // if not correct so sub is valied
                if(window[c.first] < c.second){
                    is=false;
                    break;
                }
            }
            if(is){
                int p=0;
                for(char x:sub){
                    if(window[x]-1 < frt[x]){
                        break;
                    }
                    p++;
                    window[x]--;
                }
                sub = sub.substr(p);
                if(ans =="" || sub.size() < ans.size()) ans=sub;
                window[sub[0]]--;
                sub = sub.substr(1);
            }
        }

        return ans;
        // الحمدلله حلي بنفسي ولله الحمد و الشكر
    }
};