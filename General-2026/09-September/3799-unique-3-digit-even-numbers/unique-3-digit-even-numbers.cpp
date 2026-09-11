class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        int count = 0;
        for (int d : digits) freq[d]++;

        for (int d1 = 1; d1 <= 9; d1++) {
            if (freq[d1] == 0) continue;
            freq[d1]--; 
            for (int d2 = 0; d2 <= 9; d2++) {
                if (freq[d2] == 0) continue;
                freq[d2]--;
                for (int d3 = 0; d3 <= 8; d3 += 2) {
                    if (freq[d3] > 0) {
                        count++;
                    }
                }
                freq[d2]++;
            }
            freq[d1]++;
        }

        return count;
    }
};