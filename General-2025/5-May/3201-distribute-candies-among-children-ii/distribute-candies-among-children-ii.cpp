//    __                __    ______     __         __         _______    
//    \ \      /\      / /   |   ___|   |  |       |  |       |  ___  |   
//     \ \    /  \    / /    |  |___    |  |       |  |       | |   | |   
//      \ \  / /\ \  / /     |   ___|   |  |       |  |       | |   | |   
//       \ \/ /  \ \/ /      |  |___    |  |___    |  |___    | |___| |   
//        \__/    \__/       |______|   |______|   |______|   |_______|   


class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res = 0;
        for (int i = 0; i <= min(limit, n); i++) {
            if (n - i <= 2 * limit)
                res += min(n - i, limit) - max(0, n - i - limit) + 1;
        }
        return res;
    }
};