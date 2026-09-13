class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int res=0;
        vector<vector<int>> ones1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]) ones1.push_back({i,j});
            }
        }

        for(int i=-n+1;i<n;i++){
            for(int j=-n+1;j<n;j++){
                int cnt=0;
                for(auto k:ones1){
                    int r=k[0]+i ,c=k[1]+j;
                    if(r<0 || r>=n || c<0 || c>=n) continue;
                    if(img2[r][c]) cnt++;
                }
                res=max(res,cnt);
            }
        }

        return res;
    }
};