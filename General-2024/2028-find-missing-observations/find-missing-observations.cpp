class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        long sum = accumulate(rolls.begin(), rolls.end(), 0L);
        long total_miss = mean*(n+m)-sum;
        if(total_miss < n || total_miss > 6*n){
            return {};
        }

        int av = total_miss/n ,mod= total_miss%n;
        vector<int> miss(n,av);
        for(int i=0; i<n && mod ;i++){
            miss[i]++;
            mod--;
        }

        return miss;
    }
};