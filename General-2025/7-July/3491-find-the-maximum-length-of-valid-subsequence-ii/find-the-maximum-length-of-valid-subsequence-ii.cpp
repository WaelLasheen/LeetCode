//    __                __    ______     __         __         _______    
//    \ \      /\      / /   |   ___|   |  |       |  |       |  ___  |   
//     \ \    /  \    / /    |  |___    |  |       |  |       | |   | |   
//      \ \  / /\ \  / /     |   ___|   |  |       |  |       | |   | |   
//       \ \/ /  \ \/ /      |  |___    |  |___    |  |___    | |___| |   
//        \__/    \__/       |______|   |______|   |______|   |_______|   


class Solution {
public:
    static int maximumLength(vector<int>& nums, int k) {
        //let dp[i] denote len for subsequence 
        short ans=0;
        vector<short> dp;
        for (int i=0; i<k; i++){
            dp.assign(k, 0);
            for (int x : nums){
                int j=x%k;
                dp[j]=max(dp[j], short(dp[(i+k-j)%k]+1));
                ans=max(ans, dp[j]);
            }
        }
        return ans;
        
    }
};



auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();