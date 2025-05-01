class Solution {
public:
    int addDigits(int num) {
        while(num){
            int sum =0;
            while(num){
                sum +=num%10;
                num /=10;
            }

            if(sum>9){
                num=sum;
            } else{
                return sum;
            }
        }

        return 0;
    }
};