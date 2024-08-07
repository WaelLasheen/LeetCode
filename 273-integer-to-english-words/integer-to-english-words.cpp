class Solution {
public:
    string numberToWords(int num) {
        if (!num) return "Zero";
        
        map<int, string> m1 = {
            {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"},
            {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"},
            {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"},
            {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"},
            {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"},
            {19, "Nineteen"}
        };
        
        map<int, string> m2 = {
            {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"},
            {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}
        };
        
        if (num < 20) return m1[num];
        if (num < 100) {
            if (num % 10 == 0) return m2[num];
            return m2[num / 10 * 10] + " " + m1[num % 10];
        }

        vector<string> t = {"", "Thousand", "Million", "Billion"};
        int i = 0;
        string res = "";
        
        while (num) {
            int three_digit = num % 1000;
            if (three_digit) {
                string add = "";
                int d1 = three_digit % 10;
                int d2 = (three_digit / 10) % 10;
                int d3 = (three_digit / 100) % 10;
                
                if (d3) add = m1[d3] + " Hundred";
                if (d2 >1) {
                    if (d1) {
                        add += (add.empty() ? "" : " ") + m2[d2*10] + " " + m1[d1];
                    } else {
                        add += (add.empty() ? "" : " ") + m2[d2*10];
                    }
                } else if (d2 * 10 + d1) {
                    add += (add.empty() ? "" : " ") + m1[d1+ d2*10];
                }
                
                res = add + (t[i].empty() ? "" : " " + t[i])+(res.empty()? "" : " "+res);
            }
            
            num /= 1000;
            i++;
        }
        
        return res;
    }
};
