class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin() ,banned.end());
        int sum=0 ,res=0;
        for(int i=1;i<=n;i++){
            if(!binary_search(banned.begin() ,banned.end() ,i)){
                sum +=i;
                if(sum <= maxSum){
                    res++;
                }
                else{
                    // no need to continue as all next will be invalid
                    return res;
                }
            }
        }

        return res;
    }
};