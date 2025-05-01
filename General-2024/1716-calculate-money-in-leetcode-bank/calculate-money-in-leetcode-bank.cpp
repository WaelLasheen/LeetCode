class Solution {
public:
    int totalMoney(int n) {
        int num=n/7 ,rem=n%7;

        return 28*num+(num*(num-1))*7/2 + ((rem*(rem+1))/2)+rem*num;
    }

};