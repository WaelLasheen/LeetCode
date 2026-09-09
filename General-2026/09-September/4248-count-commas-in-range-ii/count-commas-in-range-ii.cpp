#define ll long long
class Solution {
public:
    long long countCommas(long long n) {
        ll res =0;
        ll base = 1e3;
        if(n >= 1e3) res += (n/base -1)*base + (n%base)+1;
        base *=1e3;
        if(n >= base) res += (n/base -1)*base + (n%base)+1;
        base *=1e3;
        if(n >= base) res += (n/base -1)*base + (n%base)+1;
        base *=1e3;
        if(n >= base) res += (n/base -1)*base + (n%base)+1;
        base *=1e3;
        if(n >= base) res += (n/base -1)*base + (n%base)+1;
        return res;
    }
};