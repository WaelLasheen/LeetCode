class Solution {
public:
    string longestDiverseString(int a, int b, int c){
        priority_queue<pair<int,char>> pq;
        if(a) pq.push({a,'a'});
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});
        string res="";
        
        while(pq.size()){
            int n=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            int len=res.size();
            if(len>1 && res[len-1]==res[len-2]&&res[len-2]==ch){
                if(pq.empty()) break;

                int n2=pq.top().first;
                char ch2=pq.top().second;
                pq.pop();
                res +=ch2;
                n2--;
                if(n2){
                    pq.push({n2,ch2});
                }
            }

            res +=ch;
            n--;
            if(n){
                pq.push({n,ch});
            }
        }

        return res;

    }
};