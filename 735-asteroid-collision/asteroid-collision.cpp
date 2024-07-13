class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>orpt;
        for(int a:asteroids){
            re:if(!orpt.size()) orpt.push(a);
            else{
                if(a*orpt.top()>0 || orpt.top()<0) orpt.push(a);
                else{
                    if(abs(a)==abs(orpt.top())) orpt.pop();
                    else if(abs(a) > orpt.top()){ 
                        orpt.pop();
                        goto re;
                    }
                }
            }
        }
        vector<int>rem;
        while(orpt.size()){
            rem.insert(rem.begin(),orpt.top());
            orpt.pop();
        }
        return rem;
    }
};