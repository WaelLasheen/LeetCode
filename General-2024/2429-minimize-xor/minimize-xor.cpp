class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bitc=0;
        while(num2){
            bitc +=(num2&1);
            num2 >>=1;
        }
        int res=0;
        vector<bool> v(32,false);
        for(long i=31;i>=0;i--){
            if(num1&(1<<i)){
                res += (1<<i);
                v[i]=true;
                bitc--;
                if(!bitc) return res;
            }
        }

        for(long i=0;i<32;i++){
            if(!v[i]){
                res += (1<<i);
                v[i]=true;
                bitc--;
                if(!bitc) return res;
            }
        }

        return res;
    }
};