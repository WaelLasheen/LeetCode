class Solution {
public:
    bool isPalindrome(int x) {
        string n = to_string(x);
        for(int i=0,j=n.size()-1 ;i<n.size()/2 ;i++,j--){
            if(n[i]!=n[j])
            return false;
        }
        return true;
    }
};