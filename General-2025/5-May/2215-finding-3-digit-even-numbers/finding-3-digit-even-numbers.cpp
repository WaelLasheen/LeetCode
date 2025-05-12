class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> res;
        vector<int> mp(10,0);
        for(int i:digits){
            mp[i]++;
        }

        for(int i=1e2;i<1e3;i+=2){
            unordered_map<int,int> mp2;
            int n=i;
            while(n){
                mp2[n%10]++;
                n /=10;
            }
            bool add=true;
            for(auto [k,v]:mp2){
                if(mp[k]<v){
                    add=false;
                }
            }

            if(add){
                res.push_back(i);
            }
        }

        return res;
    }
};