class Solution {
public:
    int maxDifference(string s) {
        int mo=0 ,me=INT_MAX;
        map<char,int> mp;
        for(char i:s){
            mp[i]++;
        }

        for(auto i:mp){
            if(i.second&1){
                mo=max(mo,i.second);
            }
            else{
                me=min(me,i.second);
            }
        }

        return mo-me;
    }
};