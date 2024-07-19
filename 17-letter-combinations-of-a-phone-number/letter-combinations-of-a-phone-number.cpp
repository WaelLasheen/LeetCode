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

    void backtrack(string& digits,int index,string curr){
        if(index >= digits.size()){
            if(curr.size())
                out.push_back(curr);
            return;
        }
        
        for(char i:pk[digits[index]]){
            backtrack(digits,index+1,curr+i);
        }
    }

    vector<string> letterCombinations(string digits) {
        backtrack(digits,0,"");
        return out;
    }
};
