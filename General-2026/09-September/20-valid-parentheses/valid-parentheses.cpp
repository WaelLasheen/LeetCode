class Solution {
public:
    bool isValid(string s) {
        stack <char> tub;
        if(s.size()%2==1) return false;
        // if(s[0]==']' || s[0]=='}' || s[0]==')') return false;
        for(char i : s){
            if(i=='(' || i=='{' || i=='['){
                tub.push(i);
            }
            else{
                if(!tub.size()) return false;
                if(i==']' && tub.top()=='[')
                    tub.pop();
                else if(i==')' && tub.top()=='(')
                    tub.pop();
                else if(i=='}' && tub.top()=='{')
                    tub.pop();
                else
                    return false;
            }
        }
        return !tub.size();
    }
};