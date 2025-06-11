class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        
        vector<int> n;
        while(x){
            n.push_back(x%10);
            x /=10;
        }

        int l=0,r=n.size()-1;
        while(l<r){
            if(n[l++] !=n[r--]){
                return false;
            }
        }

        return true;
    }
};