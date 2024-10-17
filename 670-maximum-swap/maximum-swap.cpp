class Solution {
public:
    int maximumSwap(int num) {
        string s= to_string(num);
        int len=s.size();
        vector<pair<char,int>> v(len,{s[len-1],len-1});
        for(int i=len-2;i>=0;i--){
            if(s[i]>v[i+1].first){
                v[i]={s[i],i};
            }
            else{
                v[i]=v[i+1];
            }
        }
        for(int i=0;i<len;i++){
            if(s[i] !=v[i].first){
                int it= v[i].second;
                swap(s[i],s[it]);
                break;
            }
        }

        return stoi(s);

    }
        
};