class Solution {
public:
    string fractionAddition(string expression) {
        int nume=0 ,dome=1;     // numerator  and  denominator
        int s= expression.size();
        for(int i=0;i<s; ){
            int sig=1;
            if(expression[i]=='+') i++;
            else if(expression[i]=='-'){
                sig =-1;
                i++;
            }
            // current numerator
            int num=0;
            while(isdigit(expression[i])){
                num = num*10 + (expression[i]-'0');
                i++;
            }
            // don't forget sign!
            // may be it negative \U0001f978
            num *= sig;

            i++;    // to skip / sign

            // current denominator
            int dom=0;
            while(i<s && isdigit(expression[i])){
                dom = dom*10 + (expression[i]-'0');
                i++;
            }
            
            // calculate expression of 2 fraction
            nume = nume * dom + dome * num;
            dome = dome * dom;

            // reduce fraction as posible 
            // if you don't do this now and try to do it at end that may cause overflow
            int common = abs(__gcd(nume ,dome));
            nume /=common;
            dome /=common;
        }

        return to_string(nume)+"/"+to_string(dome);
    }
};