class Solution {
public:
    string sortVowels(string s) {
        map<char,int> mp;
        set<char> vowels={'a','e','i','o','u','A','E','I','O','U'};
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