class Solution {
public:
    int minimumDeletions(string s) {
        int len = s.size();
        vector<int> rac(len,0);     // Right A Counter
        for(int i=len-2 ;i>-1;i--){
            if(s[i+1]=='a'){
                rac[i]=rac[i+1]+1;
            }else{
                rac[i]=rac[i+1];
            }
        }
        
        int res = len;
        // no need to use array because we can calculate it when we loop
        int lbc=0;  // Left B Counter
        for(int i=0;i<len;i++){
            // we take (left b count + right a count) because that is what we need to remove
            res = min(res ,lbc+rac[i]);
            // don't foget to update counter of b
            if(s[i]=='b') lbc++;
        }

        return res;
    }
};