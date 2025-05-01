class Solution {
public:
    int minBitFlips(int start, int goal) {
        goal ^= start;

        int flip=0;
        while(goal){
            if(goal & 1){
                flip++;
            }

            goal >>=1;
        }

        return flip;
    }
};