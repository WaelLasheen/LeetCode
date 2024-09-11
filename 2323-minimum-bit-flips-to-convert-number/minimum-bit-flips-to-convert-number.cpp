class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flip=0;
        while(start || goal){
            int sb = start&1 ,gb = goal&1;
            if(sb != gb){
                flip++;
            }

            goal /=2;
            start /=2;
        }

        return flip;
    }
    // 1010
    // 0111
};