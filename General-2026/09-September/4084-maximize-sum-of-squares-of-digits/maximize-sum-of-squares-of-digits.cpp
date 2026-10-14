#define ll long long
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > num * 9) return "";

        int n9 = sum / 9;
        int rem = sum % 9;
        bool has_rem = (rem > 0);
        int n0 = num - n9 - (has_rem ? 1 : 0);

        string res = "";
        
        res.append(n9, '9');
        if (has_rem) {
            res += to_string(rem);
        }
        res.append(n0, '0');

        return res;
    }
};