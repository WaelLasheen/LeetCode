class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = n*(n+1)/2;    // sum of number from 1 to n
        int div = n/m;      // number of nums that div by m
        int dm = div*(div+1)*m;     // 2 * sum of number that div by m

        return sum-dm;
    }
};