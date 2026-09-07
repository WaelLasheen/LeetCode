class Solution {
public:
    int kthFactor(int n, int k) {
        for(int i=1;i<=n;i++){
            if(!(n%i)){
                k--;
                if(!k){
                    return i;
                }
            }
        }

        return -1;
    }
};