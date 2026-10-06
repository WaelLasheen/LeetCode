class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> inval;
        for(const char i:s){
            if(inval.size() && i==')' && inval.top()=='('){
                inval.pop();
            }

            else{
                inval.push(i);
            }
        }

        return inval.size();
    }
};