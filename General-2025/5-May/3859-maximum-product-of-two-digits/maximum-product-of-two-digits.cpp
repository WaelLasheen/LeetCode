class Solution {
public:
    int maxProduct(int n) {
        vector<int> mp(10,0);
        while(n){
            mp[n%10]++;
            n /=10;
        }

        int res=0;
        for(int i=9 ;i>-1;i--){
            if(!res && mp[i]){
                mp[i]--;
                res = i;
            }

            if(res && mp[i]){
                res *=i;
                break;
            }
        }

        return res;
    }
};