class Solution {
public:
    bool checkValidString(string s) {
        stack<int> star ,open;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') open.push(i);
            else if(s[i]=='*') star.push(i);
            else{
                if(!star.size() && !open.size()) return false;
                else if(open.size()) open.pop();          
                else if(star.size()) star.pop();
            }  
        }
        while(open.size()){
            if(!star.size() || star.top() < open.top()) return false;
            open.pop();
            star.pop();
        }
        return true;
    }
};