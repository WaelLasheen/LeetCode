class Solution {
public:
    bool rotateString(string s, string goal) {
        queue<char> q1,q2;
        for(char i:s) q1.push(i);
        for(char i:goal) q2.push(i);
        int t=s.size()+1;
        while(t--){
            if(q1==q2) return true;
            q1.push(q1.front());
            q1.pop();
        }

        return false;
    }
};