class Solution {
public:
    int minOperations(string s) {
        int s0=0 ,s1=0;
        for(int i=0;i<s.size();i++){
            if(!(i&1)){
                s[i]=='1' ? s0++ :s1++;
            } else{
                s[i]=='0' ? s0++ :s1++;
            }
        }

        return min(s0,s1);
    }
};