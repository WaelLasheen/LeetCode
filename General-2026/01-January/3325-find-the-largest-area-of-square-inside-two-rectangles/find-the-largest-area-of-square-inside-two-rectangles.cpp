#define ll long long
class Solution {
public:
    int delta(int s1 ,int s2 ,int e1 ,int e2){
        int s = max(s1 ,s2);
        int e= min(e1 ,e2);
        return max(0,e-s);
    }

    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        ll mxArea=0;
        int n=bottomLeft.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dx = delta(bottomLeft[i][0] ,bottomLeft[j][0],topRight[i][0] ,topRight[j][0]);
                int dy = delta(bottomLeft[i][1] ,bottomLeft[j][1],topRight[i][1] ,topRight[j][1]);
                int side = min(dx,dy);
                ll area = 1LL *side*side;
                mxArea = max(mxArea ,area);
            }
        }

        return mxArea;
    }
};