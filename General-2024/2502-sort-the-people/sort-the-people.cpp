class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int s=names.size();
        vector<pair<int,string>> hn(s);    // height and name
        for(int i=0;i<s;i++){
            hn[i]={heights[i],names[i]};
        }
        sort(hn.rbegin(),hn.rend());
        for(int i=0;i<s;i++){
            names[i]=hn[i].second;
        }
        return names;
        
    }
};