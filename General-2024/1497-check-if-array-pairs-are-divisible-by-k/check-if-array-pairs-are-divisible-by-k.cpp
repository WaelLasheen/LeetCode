class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> fr(k,0);
        for(int i:arr){
            fr[(k+i%k)%k]++;
        }

        if(fr[0]&1) return false;

        for(int i=1;i<=k/2;i++){
            if(fr[i] != fr[k-i]){
                return false;
            }
        }

        return true;
    }
};