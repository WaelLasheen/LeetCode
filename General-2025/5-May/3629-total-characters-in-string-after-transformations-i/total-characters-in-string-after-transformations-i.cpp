class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int mod= 1e9+7;
        int res=s.size();
        vector<int> mp(27,0);
        for(char i:s){
            mp[i-'a']++;
        }

        while(t--){
            for(int i=25;i>-1;i--){
                mp[i+1]=mp[i]%mod;
            }
            if(mp[26]){
                // mp[0] = mp[26]%mod;
                mp[1] = (mp[1] + mp[26])%mod;
                res = (res + mp[26])%mod;
            }
            mp[0] = mp[26]%mod;
        }

        return res%mod;
    }
};