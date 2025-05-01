class Solution {
public:
    int countPrimes(int n) {
        vector<bool> nums(n+1,true);
        vector<int> prim;
        for(long i=2;i<=n;i++){
            if(nums[i]){
                prim.push_back(i);
                for(long j= i*i;j<=n;j +=i){
                    nums[j]=false;
                }
            }
        }
        int s= prim.size();
        return s && prim.back()==n ? s-1 : s;
    }
};