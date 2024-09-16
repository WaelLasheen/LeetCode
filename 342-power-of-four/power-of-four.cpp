class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1) return false;
        double x = log(n)/log(4);

        return x==int(x);
    }
};