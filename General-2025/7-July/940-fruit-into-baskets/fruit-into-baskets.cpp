class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int res=0 ,curr=0;
        int l=0 ,r=0;
        
        while(r<fruits.size()){
            mp[fruits[r++]]++;
            curr++;

            while(mp.size() >2){
                mp[fruits[l]]--;
                curr--;
                if(!mp[fruits[l]]){
                    mp.erase(fruits[l]);
                }
                l++;
            }

            res=max(res,curr);
        }

        return res;
    }
};