class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int a=arr[0][0] ,b=arr[0].back() ,maxDis=0;
        for(int i=1;i<arr.size();i++){
            int l=arr[i].size()-1;
            maxDis=max(maxDis ,arr[i][l]-a);
            maxDis=max(maxDis ,b-arr[i][0]);

            a=min(a,arr[i][0]);
            b=max(b,arr[i][l]);
        }

        return maxDis;
    }
};