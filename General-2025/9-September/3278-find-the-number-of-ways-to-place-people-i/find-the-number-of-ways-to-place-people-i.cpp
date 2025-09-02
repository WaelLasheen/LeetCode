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
                int y1= points[i][1] ,y2= points[j][1];
                bool isValid=  y1>= y2;
                for(int k=i+1;isValid && k<j;k++){
                    int y3= points[k][1];
                    if(y3 >= y2 && y3 <= y1){
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