class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res=0 ,rem=0;
        while(numBottles){
            res += numBottles;
            rem += numBottles % numExchange;
            numBottles /=numExchange;
            if(rem >= numExchange){
                numBottles += rem/numExchange;
                rem = rem%numExchange;
            }
        }

        return res;
    }
};