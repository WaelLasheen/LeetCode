class Solution {
public:
    int numberOfMatches(int n) {
        int res=0;
        while(n >1){
            res +=(n+1)/2;
            n /=2;
        }

        return res;
    }
};