class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> con; // we will store score & ( -> 0
        for(char i:s){
            if(i=='(') con.push(0);
            else{
                int score = 0;
                while(con.top()){
                    score += con.top();
                    con.pop();
                }
                con.pop();
                con.push(max(1,2*score));
            }
        }

        int res = 0;
        while(con.size()){
            res +=con.top();
            con.pop();
        }

        return res;
    }
};