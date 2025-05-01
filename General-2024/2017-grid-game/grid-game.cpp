class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<vector<long>> pref(2,vector<long>(n));
        for(int i=0;i<n;i++){
            pref[0][i] = grid[0][i];
            if(i){
                pref[0][i] += pref[0][i-1];
            }
        }
        for(int i=n-1;i>=0;i--){
            pref[1][i] = grid[1][i];
            if(i!=n-1){
                pref[1][i] += pref[1][i+1];
            }
        }

        long sum=LONG_MAX;
        for(int i=0;i<n;i++){
            long l0= pref[0][n-1]-pref[0][i];
            long l1= pref[1][0]-pref[1][i];
            long rem=max(l0,l1);
            sum=min(rem,sum);
        }

        return sum;
    }
};

/*
    20,3 ,20,17,2 ,12,15,17,4 ,15
    20,10,13,14,15,5 ,2 ,3 ,14,3

    20,23,43,60,62,74,89,106,110,125
    99,79,69,56,42,27,22,20 ,17 ,3
    105 102 82 65 63 72 77 79 82 96
    min is 63
*/