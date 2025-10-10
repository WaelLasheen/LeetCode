class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int res = INT_MIN, s= energy.size();
        for(int i=s-1;i >= s-k;i--){
            res = max(res ,energy[i]);
            for(int j=i-k;j>-1;j-=k){
                energy[j] += energy[j+k];
                res = max(res ,energy[j]);
            }
        }

        return res;
    }
};

// [5,-2,-10,1,5,10,7,11,-5,1]
// [5,-2,-10,6,3,0,13,14,-5,14]