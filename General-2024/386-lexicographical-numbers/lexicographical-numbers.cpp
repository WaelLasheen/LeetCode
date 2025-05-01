class Solution {
public:
    vector<int> res;
    void solve(int n ,int num){
        if(res.size() == n){
            return;
        }

        for(int i=0;i<=9;i++){
            if(num*10+i && num*10+i <=n){
                res.push_back(num*10+i);
                if(num*100+i <=n){
                    solve(n,num*10+i);
                }
            }
        }
    }

    vector<int> lexicalOrder(int n) {
        solve(n ,0);
        return res;
    }
};