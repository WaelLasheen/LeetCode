class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size() ,res=-1 ,mxd=n;
        vector<int> step1(n,-1) ,step2(n,-1);
        steps(edges,step1,node1);
        steps(edges,step2,node2);

        for(int i=0;i<n;i++){
            if(step1[i] !=-1 && step2[i] !=-1){
                int mx =max(step1[i] ,step2[i]);
                if(mxd > mx){
                    mxd= mx;
                    res=i;
                }
            }
        }

        return res;
    }

private:
    void steps(vector<int>& edges ,vector<int>& step ,int curr){
        int it=0;
        while(curr !=-1 && step[curr] ==-1){
            step[curr]= it;
            it++;
            curr = edges[curr]; // go to next node
        }
    }
};

//example1
//  0 -1 1 2
// -1  0 1 2

//example2
//  0  1 2
// -1 -1 0