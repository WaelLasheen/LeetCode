class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int mx=prices.back();
        for(int i=prices.size()-2;i>-1;i--){
            if(prices[i] >mx){
                mx=prices[i];
            } else{
                res = max(res ,mx-prices[i]);
            }
        }

        return res;
    }
};