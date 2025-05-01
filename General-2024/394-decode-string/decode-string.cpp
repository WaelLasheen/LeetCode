class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string result = "";
        int num = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch == '[') {
                numStack.push(num);
                strStack.push(result);
                num = 0;
                result = "";
            } else if (ch == ']') {
                string temp = result;
                for (int i = 1; i < numStack.top(); i++) {
                    result += temp;
                }
                numStack.pop();
                result = strStack.top() + result;
                strStack.pop();
            } else {
                result += ch;
            }
        }

        return result;
    }
};