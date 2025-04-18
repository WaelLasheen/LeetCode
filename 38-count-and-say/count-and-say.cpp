class Solution {
public:
    string countAndSay(int n) {
        string num="1";

        return helper(num,n-1);
    }

private:
    string helper(string num ,int n){
        if(!n) return num;

        char curr=num[0];
        int cnt=0;
        string next="";

        for(char i:num){
            if(curr== i){
                cnt++;
            } 
            else{
                next = next + to_string(cnt)+curr;
                cnt=1;
                curr=i;
            }
        }
        // don't forget to add last value
        next = next + to_string(cnt)+curr;

        return helper(next,n-1);
    }
};

/*
    1
    11
    21
    1211
    111221
    312211
    13112221
    1113213211
    31131211131221
    13211311123113112211
    11131221133112132113212221
*/