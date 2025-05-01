class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()&1){
            return false;
        } 

        stack<int> lock ,unlock;
        for(int i=0;i<s.size();i++){
            if(locked[i]=='0'){
                unlock.push(i);
            }
            else{
                if(s[i]=='('){
                    lock.push(i);
                }
                else{
                    if(lock.size()){
                        lock.pop();
                    }
                    else if(unlock.size()){
                        unlock.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        while(lock.size() && unlock.size() && lock.top() < unlock.top()){
            lock.pop();
            unlock.pop();
        }

        return lock.empty();
    }
};