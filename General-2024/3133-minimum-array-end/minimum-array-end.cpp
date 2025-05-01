#define ll long long
class Solution {
public:
    long long minEnd(int n, int x) {
        int b=64;
        vector<ll> bits(b,0);
        int it=0;
        while(x){
            bits[it] = x&1;
            x >>=1;
            it++;
        }
        n--;
        it=0;
        while(n){
            if(!bits[it]){
                bits[it] = n&1;
                n >>=1;
            }
            it++;
        }

        ll res=0;
        for(ll i=0;i<b;i++){
            res += (static_cast<ll>(bits[i]) << i);
        }

        return res;
    }
};