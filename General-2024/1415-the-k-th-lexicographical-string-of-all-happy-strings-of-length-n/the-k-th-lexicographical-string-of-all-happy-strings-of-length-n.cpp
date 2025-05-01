class Solution {
public:
    string getHappyString(int n, int k) {
        if(k > (3<<(n-1))){
            return "";
        }

        queue<string> q;
        q.push("");
        while(k){
            string curr=q.front();
            q.pop();
            for(char i='a';i<'d';i++){
                if(curr.empty() || curr.back()!=i){
                    q.push(curr+i);
                    if(curr.size()+1 ==n) k--;
                }
                if(!k) break;
            }
        }

        return q.back();
    }
};