class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> mp;
        for(int i:arr){
            mp[(k+i%k)%k]++;
        }

        if(mp[0]&1) return false;

        for(int i=1;i<=k/2;i++){
            if(mp[i] != mp[k-i]){
                return false;
            }
        }

        return true;
    }
};