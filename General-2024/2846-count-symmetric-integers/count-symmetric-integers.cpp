class Solution {
public:
    bool help(int num){
        if(num<100 && num>10){
            return num%10 == num/10;
        }
        if(num<1e4 && num>1e3){
            return num%10 + (num/10)%10 == (num/100)%10 + num/1000;
        }

        return false;
    }

    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        while(low <= high){
            cnt += help(low);
            low++;
        }

        return cnt;
    }
};