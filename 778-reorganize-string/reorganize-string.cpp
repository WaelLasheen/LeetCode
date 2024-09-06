class Solution {
public:
    string reorganizeString(string s) {
        if(s.size()==1) return s;

        int max_fr=0;
        map<char,int> fr;
        for(const char i: s){
            fr[i]++;
            max_fr = max(fr[i],max_fr);
        }

        if(fr.size()==1 || max_fr-1 > s.size()-max_fr) return "";

        priority_queue<pair<int,char>> pq;
        for(auto i:fr){
            pq.push({i.second ,i.first});
        }

        vector<string> subs(max_fr ,string(1,pq.top().second));
        pq.pop();
        
        while(pq.size()){
            int i=0;
            int t=pq.top().first;
            char c=pq.top().second;
            while(true){
                subs[i] += c;
                t--;
                if(!t){
                    pq.pop();
                    t=pq.top().first;
                    c=pq.top().second;
                    if(!(pq.size())){
                        break;
                    }
                }

                i = (i+1)%max_fr;
            }
        }

        string res="";
        for(const string i:subs){
            res += i;
        }

        return res;
    }
};