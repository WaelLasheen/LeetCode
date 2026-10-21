class Solution {
public:
    int minOperations(string s) {
        if(s.size()==2 && s[0] > s[1]){
            return -1;
        }
        char mn='z',mx='a';
        int mni=0,mxi=0;
        int len = s.size();
        bool isSorted = true;
        for(int i=0,j=len-1;i<len;i++,j--){
            if(s[i] < mn){
                mn = s[i];
                mni=i;
            }
            if(s[j] > mx){
                mx = s[j];
                mxi=j;
            }
            if(i && s[i-1] > s[i]){
                isSorted = false;
            }
        }
        if(isSorted) return 0;
        if(mni==0 || mxi == len-1) return 1;
        if(mxi==0 && mni == len-1) return 3;
        return 2;
    }
};