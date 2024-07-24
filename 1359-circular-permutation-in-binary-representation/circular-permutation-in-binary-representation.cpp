class Solution {
public:
    vector<int> res;
    vector<bool> v;
    void solve(int curr, int n){
        if(res.size()== (1<<n)){
            int x=res[0]^res[(1<<n) -1];
            int c=0;
            while(x){
                c +=(x&1);
                x >>=1;
            }
            if(c==1) return;
        }

        if(!(v[curr])){
            res.push_back(curr);
            v[curr]=true;
            for(int i=0;i<n;i++){
                int next = curr ^(1<<i);
                if(!(v[next])){
                    solve(next,n);
                }
            }
        }
    }

    vector<int> circularPermutation(int n, int start) {
        v.resize(1<<n,false);
        solve(start,n);
        return res;
    }
};