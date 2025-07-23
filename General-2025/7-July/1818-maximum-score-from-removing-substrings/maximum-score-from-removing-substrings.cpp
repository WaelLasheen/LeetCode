class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string want1 = "ab";
        string want2 = "ba";
        int maxVal = max(x, y);
        int minVal = min(x, y);

        if (x < y) {
            swap(want1, want2);  // Make sure "ab" is always the string we process first if x < y
        }

        stack<char> con;
        int val = 0;
        for (char i : s) {
            if (!con.empty() && string(1, con.top()) + i == want1) {
                val += maxVal;
                con.pop();
            } else {
                con.push(i);
            }
        }

        string remaining;
        while (!con.empty()) {
            remaining.push_back(con.top());
            con.pop();
        }

        reverse(remaining.begin(), remaining.end());
        for (char i : remaining) {
            if (!con.empty() && string(1, con.top()) + i == want2) {
                val += minVal;
                con.pop();
            } else {
                con.push(i);
            }
        }

        return val;
    }
};
