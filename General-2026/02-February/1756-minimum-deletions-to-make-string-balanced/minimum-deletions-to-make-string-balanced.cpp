class Solution {
public:
    int minimumDeletions(string s) {
        int len = s.size();
        vector<int> cntRA(len,0);   // count of right A to current index
        for(int i=len-2 ;i>-1;i--){
            cntRA[i] = cntRA[i+1] + (s[i+1]=='a');
        }

        int res=len ,cntLB=0;
        for(int i=0;i<len;i++){
            res = min(res ,cntLB + cntRA[i]);
            cntLB += (s[i]=='b');
        }

        return res;
    }
};