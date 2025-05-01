class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0 ,mn=INT_MAX;
        for(int i:prices){
            mn = min(mn,i);
            res = max(res,i-mn);
        }

        return res;
    }
};