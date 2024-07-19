class Solution {
public:
    map<char,string> pk{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    
    vector<string> out;

    void backtrack(string& digits,int index,string& curr){
        if(index >= digits.size()){
            if(curr.size())
                out.push_back(curr);
            return;
        }
        
        for(char i:pk[digits[index]]){
            string n = curr+i;
            backtrack(digits,index+1,n);
        }
    }

    vector<string> letterCombinations(string digits) {
        string curr="";
        backtrack(digits,0,curr);
        return out;
    }
};
