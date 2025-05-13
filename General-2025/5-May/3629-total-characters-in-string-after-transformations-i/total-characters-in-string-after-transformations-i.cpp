#define ll long long
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const ll mod = 1e9 + 7;
        ll freq[26] = {0};

        for (char c : s) freq[c - 'a']++;

        while (t--) {
            ll nextFreq[26] = {0};
            for (int i = 0; i < 26; i++) {
                if (i == 25) {  
                    nextFreq[0] = (nextFreq[0] + freq[i]) % mod;  
                    nextFreq[1] = (nextFreq[1] + freq[i]) % mod;  
                } else {  
                    nextFreq[i + 1] = (nextFreq[i + 1] + freq[i]) % mod;
                }
            }
            for (int i = 0; i < 26; i++) {
                freq[i] = nextFreq[i];
            }
        }

        ll res = 0;
        for (int i = 0; i < 26; i++) {
            res = (res + freq[i]) % mod;
        }
        return res;
    }
};
