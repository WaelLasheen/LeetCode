class Solution {
public:
    int divide(long dividend, long divisor) {
        // Special case to handle overflow
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;  // Return the maximum 32-bit integer value
        }

        // To handle negative values
        bool neg = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
        dividend = labs(dividend);
        divisor = labs(divisor);

        long res = 0;
        while (dividend >= divisor) {
            long temp = divisor , steps=1;
            while(dividend >= (temp <<1)){
                temp <<=1;
                steps <<=1;
            }
            
            dividend -= temp;
            res += steps;
        }

        return neg ? -res : res;
    }
};