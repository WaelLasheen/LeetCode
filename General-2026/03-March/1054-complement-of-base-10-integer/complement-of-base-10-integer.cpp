class Solution {
public:
    int bitwiseComplement(int n) {
        if(!n) return 1;
        
        int res=0 ,p=0;
        while(n){
            int b = n&1;
            res += (!b)<<p;
            n = n>>1;
            p++;
        }

        return res;
    }
};