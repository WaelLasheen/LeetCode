class Solution {
public:
    int mySqrt(int x) {
        long i=0;
        for( ;i*i<x;i++){
            if(x> i*i && x<(i+1)*(i+1)){
                return i;
            }
        }

        return i;
    }
};