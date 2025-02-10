class Solution {
public:
    string clearDigits(string s) {
        stack<char> con;
        for(char i:s){
            if(i>='0' && i<='9') con.pop();
            else con.push(i);
        }
        string res="";
        while(con.size()){
            res = con.top()+res;
            con.pop();
        }
        return res;
    }
};