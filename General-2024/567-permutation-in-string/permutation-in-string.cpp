class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> fr(26,0) ,mp(26,0);
        for(const char i:s1){
            fr[i-'a']++;
        }
        int l=0,r=0;
        while(r<s1.size()){
            mp[s2[r]-'a']++;
            r++;
        }
        if(fr==mp) return true;

        while(r<s2.size()){
            mp[s2[r]-'a']++;
            mp[s2[l]-'a']--;
            l++;
            r++;
            if(fr==mp) return true;
        }

        return false;
    }
};