class Solution {
public:
    vector<string>out;
    void backtrack(int opens,int closes,int n ,string& curr){
        if(opens==closes && opens==n){
            out.push_back(curr);
            return;
        }
        if(opens<n){
            string next = curr+'(';
            backtrack(opens+1,closes,n,next);
        }
        if(closes < opens){
            string next = curr+')';
            backtrack(opens,closes+1,n,next);
        }
    }

    vector<string> generateParenthesis(int n) {
        string curr="";
        backtrack(0,0,n,curr);
        return out;
    }
};