class Solution {
public:
    int maximumSwap(int num) {
        string s= to_string(num);
        int len=s.size();
        for(int i=0;i<len;i++){
            char m=s[i];
            int it=i;
            for(int j=i+1;j<len;j++){
                if(s[j]>=m){
                    m=s[j];
                    it=j;
                }
            }
            if(m>s[i]){
                swap(s[i],s[it]);
                break;
            }
        }

        return stoi(s);

    }
        
};