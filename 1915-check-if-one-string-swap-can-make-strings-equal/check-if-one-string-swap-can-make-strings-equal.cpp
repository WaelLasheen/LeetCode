class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        map<char,int> mp;
        int p1=0 ,p2=0 ,ct=0;
        while(p1<s1.size()){
            if(s1[p1] != s2[p2]){
                ct++;
                mp[s1[p1]]++;
                mp[s2[p2]]--;
            }

            p1++;
            p2++;
        }

        for(auto i:mp){
            if(i.second){
                return false;
            }
        }
        
        return ct<=2;
    }
};