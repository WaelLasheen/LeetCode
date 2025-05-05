class Solution {
public:
    int numTilings(int n) {
        vector<long>arr(1001,0);
        long mod=1e9+7;
        arr[0]=1;
        arr[1]=1;
        arr[2]=2;
        arr[3]=5;
        for(int i=4;i<=n;i++){
            arr[i]=(2*arr[i-1]+arr[i-3])%mod;
        }
        
        return arr[n];
    }
};