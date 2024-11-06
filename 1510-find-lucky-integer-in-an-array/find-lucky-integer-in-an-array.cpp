class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> mp;
        for(int i:arr) mp[i]++;
        int res=-1;
        for(int i:arr){
            if(mp[i]==i){
                res=max(res,i);
            }
        }

        return res;
    }
};