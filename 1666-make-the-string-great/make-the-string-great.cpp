class Solution {
public:
    string makeGood(string s) {
        const int diff ='a'-'A';
        string res="";
        stack<char>stack;
        for(char i:s){
            if(!stack.size()) stack.push(i);
            else if(abs(stack.top()-i)==diff) stack.pop();
            else stack.push(i);
        }
        while(stack.size()){
            res += stack.top();
            stack.pop();
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};