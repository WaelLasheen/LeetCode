class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        // n=2
        // 0 1 3 2  >>>  3 2 0 1
        int s=1<<n;
        vector<int> res(s);
        for(int i=0;i<s;i++){
            res[i]= i^(i>>1);   // i xor i/2
        }
        auto it = find(res.begin(),res.end(),start);
        reverse(res.begin() ,it);
        reverse(it, res.end());
        reverse(res.begin() ,res.end());

        return res;
    }
};