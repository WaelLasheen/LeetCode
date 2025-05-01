class Solution {
public:
    int reverse(int x) {
        // if(x > 2147483647 || x< -2147483648) return 0;
        
        string n = to_string(x);
        std::reverse(n.begin(),n.end());
        if(x<0){
            n.pop_back();
            n = "-"+n;
            if(n.size()>=11 &&  n>"-2147483648") return 0;
            return stoi(n);
        }
        if(n.size()>=10 && n>"2147483647") return 0;
        return stoi(n);
    }
};