class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> res;
        vector<int> mp(10,0);
        for(int i:digits){
            mp[i]++;
        }

        for(int i=1e2;i<1e3;i+=2){
            vector<int> mp2(10,0);
            int n=i;
            while(n){
                mp2[n%10]++;
                n /=10;
            }
            bool add=true;
            for(int k=0;k<10;k++){
                if(mp[k]< mp2[k]){
                    add=false;
                    break;
                }
            }

            if(add){
                res.push_back(i);
            }
        }

        return res;
    }
};