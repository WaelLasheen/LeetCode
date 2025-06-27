class Solution {
public:
    int longestSubsequence(string s, int k) {
        int res=0 ,sub =log2(k)+1 ,p=0 ,curr=0;

        for(int i=s.size()-1;i>-1;i--){
            if(s[i]=='0'){
                res++;
            }
            else if(p<= sub && curr + pow(2,p) <=k){
                res++;
                curr += pow(2,p);
            }

            p++;
        }

        return res;
    }
};