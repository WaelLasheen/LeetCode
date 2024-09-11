class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flip=0;
        while(start || goal){
            if(start&1 ^ goal&1){
                flip++;
            }

            goal >>=1;
            start >>=1;
        }

        return flip;
    }
};