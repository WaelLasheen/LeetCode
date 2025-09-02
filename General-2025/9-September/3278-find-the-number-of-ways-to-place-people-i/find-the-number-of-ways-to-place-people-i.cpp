class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[0] ==b[0] ?a[1] > b[1] : a[0] < b[0];
    } 
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int res=0 ,s=points.size();
        sort(points.begin(),points.end(),cmp);

        for(int i=0;i<s;i++){
            for(int j=i+1;j<s;j++){
                bool isValid= points[i][1] >= points[j][1];
                for(int k=0;isValid && k<s;k++){
                    if(k!=i && k !=j && points[k][0] >= points[i][0] && points[k][0]<= points[j][0] && points[k][1] >= min(points[i][1] , points[j][1]) && points[k][1] <= max(points[i][1] , points[j][1])){
                        isValid = false;
                    }
                }
                if(isValid){
                    res++;
                }
            }
        }

        return res;
    }
};