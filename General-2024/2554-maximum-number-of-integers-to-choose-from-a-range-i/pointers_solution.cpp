class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin() ,banned.end());
        int sum=0 ,res=0 ,it=0;
        int len = banned.size();
        for(int i=1;i<=n;i++){
            if(it<len && banned[it]== i){
                while(it<len && banned[it]== i){
                    it++;
                }
            }

            else{
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
