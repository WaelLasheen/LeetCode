class Solution {
public:
    int maxSide(vector<int>& arr){
        sort(arr.begin(),arr.end());
        int curr=1 ,next=2 ,mx=1;
        for(int i:arr){
            if(i==next){
                next++;
            } else{
                mx= max(mx , next-curr);
                curr= i-1;
                next= i+1;
            }
        }

        return max(mx , next-curr);
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int sideA = maxSide(hBars);
        int sideB = maxSide(vBars);

        int mn = min(sideA ,sideB);
        return mn*mn;
    }
};