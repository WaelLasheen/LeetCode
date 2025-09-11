class Solution {
public:
    string sortVowels(string s) {
        map<char,int> mp;
        unordered_set<char> vowels={'A','E','I','O','U','a','e','i','o','u'};
        for(char i:s){
            if(vowels.count(i)){
                mp[i]++;
            }
        }

        for(int i=0;i<s.size();i++){
            if(vowels.count(s[i])){
                char v= mp.begin()->first;
                s[i]=v;
                mp[v]--;
                if(!mp[v]){
                    mp.erase(v);
                }
            }
        }

        return s;
    }
};