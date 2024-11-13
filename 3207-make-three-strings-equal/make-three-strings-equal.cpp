class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        if(s1[0] !=s2[0] || s2[0] !=s3[0] || s1[0] !=s3[0]){
            return -1;
        }

        int len = min({s1.size(),s2.size(),s3.size()});
        int res = s1.size()+s2.size()+s3.size() -3*len;
        for(int i=1;i<len;i++){
            if(s1[i] !=s2[i] || s2[i] !=s3[i] || s1[i] !=s3[i]){
                res +=3*(len-i);
                break;
            }
        }

        return res;
    }
};