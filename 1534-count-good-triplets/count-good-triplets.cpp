class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int cnt=0 ,s=arr.size();
        for(int i=0;i<s;i++){
            for(int j=i+1;j<s;j++){
                for(int k=j+1;k<s;k++){
                    if(abs(arr[i]-arr[j])<=a && abs(arr[k]-arr[j])<=b && abs(arr[i]-arr[k])<=c){
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};