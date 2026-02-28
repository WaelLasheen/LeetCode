class Solution {
public:
    int concatenatedBinary(int n) {
        long res=0;
        const long mod = 1e9 +7;
        for(int i=1;i<=n;i++){
            int l= log2(i)+1;   // value of shift
            res = (res<<l)%mod;
            res = (res + i)%mod;

        }

        return res;
    }
};