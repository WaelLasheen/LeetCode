class Solution {
public:
    int countOdds(int low, int high) {
        int s= high-low+1;
        if(!(s&1)) return s/2;
        if(low&1) return s/2+1;
        return s/2;
    }
};