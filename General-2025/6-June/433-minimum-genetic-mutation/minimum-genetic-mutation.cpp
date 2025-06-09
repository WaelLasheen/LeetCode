class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        map<string,bool> v;
        v[startGene]= true;
        queue<pair<string,int>> q;
        q.push({startGene,0});

        while(q.size()){
            auto [curr,level] = q.front();
            q.pop();

            if(curr== endGene){
                return level;
            }

            for(string gene:bank){
                if(!v.count(gene)){
                    int diff=0;
                    for(int i=0;i<8;i++){
                        if(gene[i] != curr[i]){
                            diff++;
                            if(diff>1){
                                break;
                            }
                        }
                    }
                    
                    if(diff==1){
                        q.push({gene,level+1});
                        v[gene]=true;
                    }
                }
            }
        }

        return -1;
    }
};