class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int d2=0 ,area=0 ,fr=0;

        for(vector<int> v:dimensions){
            int curr = v[0]*v[0] + v[1]*v[1];
            if(curr > d2){
                d2 = curr;
                fr=1;
                area= v[0] * v[1];
            }
            else if(curr == d2){
                area = max(area , v[0] * v[1]);
            }
        }

        return area;
    }
};