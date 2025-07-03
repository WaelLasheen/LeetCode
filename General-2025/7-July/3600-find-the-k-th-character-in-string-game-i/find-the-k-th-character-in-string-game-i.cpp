class Solution {
public:
    char kthCharacter(int k) {
        string w="a";
        while(w.size()<k){
            string add = "";
            for(char i:w){
                if(i=='z'){
                    add +='a';
                } else{
                    add += i+1;
                }
            }
            w +=add;
        }

        return w[k-1];
    }
};

/*
    a
    ab
    abbc
    abbcbccd
    abbcbccdbccdcdde
*/