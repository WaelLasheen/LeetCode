class Solution {
public:
    string sortVowels(string s) {
        vector<char> mp;
        unordered_set<char> vowels = {'A','E','I','O','U','a','e','i','o','u'};
        for(char i:s){
            if(vowels.count(i)){
                mp.push_back(i);
            }
        }
        sort(mp.begin(),mp.end());
        for(int i=0,j=0;i<s.size();i++){
            if(vowels.count(s[i])){
                s[i]=mp[j++];
            }
        }

        return s;
    }
};