class Solution {
public:
    bool parseBoolExpr(string expression) {
        // ! | & t f
        stack<char> logic;  // ! | &
        map<char,int> mp;   // t f
        set<char> s={'!','&','|','t','f'};
        for(char i:expression){
            if(s.count(i)){
                logic.push(i);
            }
            else if(i==')'){
                while(logic.top()=='t' || logic.top()=='f'){
                    mp[logic.top()]++;
                    logic.pop();
                }

                char l=logic.top();
                logic.pop();
                if(l=='!'){
                    if(mp['f']) logic.push('t');
                    else logic.push('f');
                }
                else if(l=='|'){
                    if(mp['t']) logic.push('t');
                    else logic.push('f');
                }
                else if(l=='&'){
                    if(mp['f']) logic.push('f');
                    else logic.push('t');
                }

                mp.clear();
            }
        }

        return logic.top()=='t';
    }
};