class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        int res=0;
        for(int i:answers){
            mp[i]++;
        }

        for(auto [k,fr]: mp){
            if(!k){
                res +=fr;
            }
            else{
                res += (fr+k)/(k+1) * (k+1);
            }
        }

        return res;
    }
};