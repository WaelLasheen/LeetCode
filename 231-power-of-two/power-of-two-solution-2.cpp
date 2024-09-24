class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1) return false;
        double l=log2(n);
        
        return int(l)==l;
    }
};
