class Solution {
public:
    string pushDominoes(string dominoes) {
        int s= dominoes.size();
        string cp= dominoes;
        queue<int> q;
        for(int i=0;i<s;i++){
            if(dominoes[i] !='.'){
                q.push(i);
            }
        }

        int cnt=q.size();

        while(q.size()){
            int i= q.front();
            q.pop();
            cnt--;

            if(dominoes[i]=='R' && i+1<s && dominoes[i+1]=='.'){
                if(!(i+2<s && dominoes[i+2]=='L')){
                    q.push(i+1);
                    cp[i+1]='R';
                }
            }

            else if(dominoes[i]=='L' && i-1>-1 && dominoes[i-1]=='.'){
                if(!(i-2>-1 && dominoes[i-2]=='R')){
                    q.push(i-1);
                    cp[i-1]='L';
                }
            }

            if(!cnt){
                dominoes = cp;
                cnt=q.size();
            }
        }

        return dominoes;
    }
};