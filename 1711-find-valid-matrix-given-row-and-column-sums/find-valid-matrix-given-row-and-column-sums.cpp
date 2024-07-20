class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int r=rowSum.size(), c=colSum.size();
        vector<vector<int>> res (r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            res[i][0]=rowSum[i];
        }
        for(int i=0;i<c;i++){
            long currColSum=0;
            for(int j=0;j<r;j++){
                currColSum += res[j][i];
            }
            int j=0;
            while(currColSum > colSum[i]){
                long diff = currColSum-colSum[i];
                int sub= min((long)res[j][i] ,diff);
                res[j][i] -= sub;
                res[j][i+1] += sub;
                currColSum -= sub;
                j++;
            }
        }

        return res;
    }
};