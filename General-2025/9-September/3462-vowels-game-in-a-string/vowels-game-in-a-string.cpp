class Solution {
public:
    bool doesAliceWin(string s) {
        int vowels=0;
        for(char i:s){
            if(i=='a' || i=='e' || i=='i' || i=='o' || i=='u' ) vowels++;
        }
        
        return vowels;
    }
};