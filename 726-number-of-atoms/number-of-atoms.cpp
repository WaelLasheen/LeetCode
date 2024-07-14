// it is easy ,but code are to long
// I realy hate this \U0001f494\U0001f972
// https://www.youtube.com/watch?v=iuK05gGBzJc

class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string, int>> stk;
        unordered_map<string, int> count;
        int n = formula.size();
        
        for (int i = 0; i < n;) {
            if (formula[i] == '(') {
                // Push the current map to stack and start a new one
                stk.push(move(count));
                count.clear();
                ++i;
            } else if (formula[i] == ')') {
                unordered_map<string, int> temp = move(count);
                count = move(stk.top());
                stk.pop();
                ++i;
                int start = i;
                while (i < n && isdigit(formula[i])) ++i;
                int multiplier = (i > start) ? stoi(formula.substr(start, i - start)) : 1;
                for (const auto& [elem, cnt] : temp) {
                    count[elem] += cnt * multiplier;
                }
            } else {
                int start = i++;
                while (i < n && islower(formula[i])) ++i;
                string element = formula.substr(start, i - start);
                start = i;
                while (i < n && isdigit(formula[i])) ++i;
                int count_val = (i > start) ? stoi(formula.substr(start, i - start)) : 1;
                count[element] += count_val;
            }
        }

        vector<pair<string, int>> elements(count.begin(), count.end());
        sort(elements.begin(), elements.end());
        
        string result;
        for (const auto& [elem, cnt] : elements) {
            result += elem;
            if (cnt > 1) result += to_string(cnt);
        }
        
        return result;
    }
};
