class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
        vector<bool> del(n,false);
        priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>> pq;
        for(int i=0;i<n;i++){
            if(s[i] !='*'){
                pq.push({s[i],-i});
            }
            else{
                del[-pq.top().second]=true;
                del[i]=true;    // delete * too
                pq.pop();
            }
        }

        string res="";
        for(int i=0;i<n;i++){
            if(!del[i]){
                res +=s[i];
            }
        }

        return res;
    }
};