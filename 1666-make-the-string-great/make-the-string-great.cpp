class Solution {
public:
    string makeGood(string s) {
        const int diff ='a'-'A';
        stack<char>stack;
        for(char i:s){
            if(!stack.size()) stack.push(i);
            else if(abs(stack.top()-i)==diff) stack.pop();
            else stack.push(i);
        }
        s="";
        while(stack.size()){
            s += stack.top();
            stack.pop();
        }
        reverse(s.begin(), s.end());

        return s;
    }
};