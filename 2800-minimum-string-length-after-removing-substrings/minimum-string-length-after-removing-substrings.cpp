class Solution {
public:
    int minLength(string s) {
        stack<char>con;
        for(char i:s){
            if(!con.size()) con.push(i);
            else{
                if(con.top()=='A'&&i=='B' || con.top()=='C'&&i=='D') con.pop();
                else con.push(i);
            }
        }
        
        return con.size();
    }
};