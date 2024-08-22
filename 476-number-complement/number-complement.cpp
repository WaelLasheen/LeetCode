class Solution {
public:
    int findComplement(int num) {
        long bits=0 ,n=num;
        while(n){
            n >>=1;
            bits++;
        }
        long m= 1<<bits;
        m--;
        return m -num;
    }
};