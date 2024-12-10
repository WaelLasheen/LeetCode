class Solution {
public:
    int maximumLength(string s) {
        map<string, int> mp;
        for (int i = 0; i < s.size(); i++) {
            string curr;
            for (int j = i; j < s.size(); j++) {
                if (curr.empty() || curr.back() == s[j]) {
                    curr += s[j];
                    mp[curr]++;
                } else {
                    break;
                }
            }
        }

        int ans = 0;
        for (auto i : mp) {
            if (i.second >= 3 && i.first.size() > ans) ans = i.first.size();
        }
        
        return ans == 0 ? -1 : ans;
    }
};