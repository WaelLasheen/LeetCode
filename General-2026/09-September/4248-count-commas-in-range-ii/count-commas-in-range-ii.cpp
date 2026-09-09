#define ll long long
class Solution {
public:
    long long countCommas(long long n) {
        ll res =0;
        for(ll base=1000;base<=n;base *=1000){
            res += (n/base -1)*base + (n%base)+1;
        }
        
        return res;
    }
};