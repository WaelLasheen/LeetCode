class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> open;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') open.push(i);
            else if(s[i]==')'){
                reverse(s.begin()+open.top()+1 ,s.begin()+i);
                open.pop();
            }
        }
        
        string ans="";
        for(char i:s){
            if(i !='(' && i !=')'){
                ans +=i;
            }
        }
        return ans;
    }
};