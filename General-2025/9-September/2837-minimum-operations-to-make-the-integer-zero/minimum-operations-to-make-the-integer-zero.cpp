# define ull unsigned long long
# define ll long long
# define u unsigned

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if(!num2){
            return popcount(u(num1));
        }

        ll n= num1;
        for(int i=1;i<=60;i++){
            n -= num2;

            if(n <i || n<0){
                return -1;
            }
            else if(i>= popcount((ull)(n))){
                return i;
            }
        }

        return -1;
    }
};