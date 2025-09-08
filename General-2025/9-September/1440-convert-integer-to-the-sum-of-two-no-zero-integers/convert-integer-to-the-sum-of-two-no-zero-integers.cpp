class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a=0 ,b=0 ,len=1;
        while(n){
            int d=n%10;
            if (d==0) {
                a+=5*len;
                b+=5*len;
                n-=10;  
            } 
            else if (d==1 && n>=10) {
                a+=6*len;
                b+=5*len;
                n-=10;  
            } 
            else {
                a+=(d-d/2)*len;
                b+=(d/2)*len;
            }
            len *=10;
            n /=10;
        }

        return {a,b};
    }
};