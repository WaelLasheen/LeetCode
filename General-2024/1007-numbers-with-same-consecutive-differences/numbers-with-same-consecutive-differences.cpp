class Solution {
public:
    vector<int> res;

    void solve(int curr ,int len ,int n ,int k){
        if(len == n){
            res.push_back(curr);
            return;
        }

        if(curr%10 + k <10){
            solve(curr*10+curr%10+k ,len+1 ,n,k);
        }
        // check k value as if k is zero it will same add and cause duplicate
        if(k && curr%10 - k >-1){
            solve(curr*10+curr%10-k ,len+1 ,n,k);
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<10;i++){
            solve(i,1,n,k);
        }
        return res;
    }
};