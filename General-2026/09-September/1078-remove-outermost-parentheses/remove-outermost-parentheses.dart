class Solution {
    String removeOuterParentheses(String s) {
        int outer=0,inner=0;
        String ans="";
        for(int i=0;i<s.length;i++){
            if(s[i]=='('){
                if(inner==0 && outer==0) outer++;
                else if(outer !=0){
                    inner++;
                    ans+=s[i];
                }
            }
            else{
                if(inner==0 && outer!=0) outer--;
                else if(inner !=0){
                    inner--;
                    ans+=s[i];
                }
            }
        }
        return ans;
    }
}