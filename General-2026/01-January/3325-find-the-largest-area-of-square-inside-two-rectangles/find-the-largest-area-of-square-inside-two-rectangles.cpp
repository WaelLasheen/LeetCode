#define ll long long
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        ll mxArea=0;
        int n=bottomLeft.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1 = max(bottomLeft[i][0] ,bottomLeft[j][0]);
                int x2= min(topRight[i][0] ,topRight[j][0]);
                int dx = max(0,x2-x1);
                int y1 = max(bottomLeft[i][1] ,bottomLeft[j][1]);
                int y2= min(topRight[i][1] ,topRight[j][1]);
                int dy = max(0,y2-y1);
                int side = min(dx,dy);
                ll area = 1LL *side*side;
                mxArea = max(mxArea ,area);
            }
        }

        return mxArea;
    }
};