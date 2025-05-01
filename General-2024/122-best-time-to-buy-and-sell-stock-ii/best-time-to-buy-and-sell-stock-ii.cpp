class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0 ,s=prices.size();
        int r=s-1;
        for(int i=s-1;i>0;i--){
            if(prices[i] < prices[i-1]){
                res += help(prices,i,r);
                r=i-1;
            }
        }

        if(r){
            res += help(prices,0,r);
        }

        return res;
    }

private:
    // this code is from Best Time to Buy and Sell Stock I
    int help(vector<int>& prices ,int l ,int r){
        int res=0 ,mn=INT_MAX;
        while(l<=r){
            mn = min(mn,prices[l]);
            res = max(res,prices[l]-mn);
            l++;
        }

        return res;
    }
};