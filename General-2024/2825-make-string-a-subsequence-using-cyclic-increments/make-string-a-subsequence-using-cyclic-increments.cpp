class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int l1=str1.size() ,l2=str2.size();
        if(l1 < l2) return false;

        string str3 = str2;    // str3[i] = str2[i]-1  [z <-a ... y <-z]
        for(int i=0;i<l2;i++){
            if(str3[i] >'a'){
                str3[i]--;
            }
            else{
                str3[i]='z';
            }
        }

        int it1=0 ,it2=0 ,it3=0;
        while(it1<l1 && it2<l2 && it3<l2){
            if(str1[it1] == str2[it2] || str1[it1] == str3[it3]){
                it2++;
                it3++;
            }

            it1++;
        }

        return it2==l2 || it3==l2;
    }
};