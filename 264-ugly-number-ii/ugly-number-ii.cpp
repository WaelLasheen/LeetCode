#define ull unsigned long long

class Solution {
public:
    int nthUglyNumber(int n) {
        set<unsigned long long> ugly={1,2,3,5};
        int t=8;
        while(t--){
            int c=ugly.size();
            ull fac=5;
            for(ull i:ugly){
                ugly.insert(i*fac);
                if(c-- ==0) break;
            }
            c=ugly.size();
            fac=3;
            for(ull i:ugly){
                ugly.insert(i*fac);
                if(c-- ==0) break;
            }
            c=ugly.size();
            fac=2;
            for(ull i:ugly){
                ugly.insert(i*fac);
                if(c-- ==0) break;
            }
        }

        return *next(ugly.begin(), n - 1);
    }
};
