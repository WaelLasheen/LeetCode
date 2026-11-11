#define ll long long
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(cost1 + cost2 <= costBoth){
            return 1LL * need1 * cost1 + 1LL * need2 * cost2;
        }

        int minNeed = min(need1,need2);
        ll res = 1LL * minNeed * costBoth;
        need1 -= minNeed;
        need2 -= minNeed;
        res += 1LL * need1 * min(cost1 , costBoth);
        res += 1LL * need2 * min(cost2 , costBoth);

        return res;
    }
};