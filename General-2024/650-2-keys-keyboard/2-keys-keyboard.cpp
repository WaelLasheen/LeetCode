class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        vector<int> fac;
        for(int i=2;i<=n;i++){
            while(n%i==0){
                fac.push_back(i);
                n /=i;
            }
            if(n==1) break;
        }

        int res=0;
        for(int i:fac) res +=i;

        return res;
    }
};