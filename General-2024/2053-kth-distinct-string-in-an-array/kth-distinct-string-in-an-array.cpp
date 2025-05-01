class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> fr;
        for (const string& s : arr) {
            fr[s]++;
        }

        for (const string& s : arr) {
            if (fr[s] == 1) {
                k--;
                if (k == 0) {
                    return s;
                }
            }
        }

        return "";
    }
};
