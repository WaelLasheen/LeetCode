class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int,int,int> ,vector<tuple<int,int,int>> ,greater<>> pq;
        vector<vector<int>> res;
        int n=nums1.size() ,m=nums2.size();
        set<pair<int,int>> v;
        pq.push({nums1[0]+nums2[0] ,0,0});
        v.insert({0,0});

        while(k--){
            auto [sum ,i,j] = pq.top();
            pq.pop();

            res.push_back({nums1[i],nums2[j]});

            if(i+1<n && !v.count({i+1,j})){
                v.insert({i+1,j});
                pq.push({nums1[i+1]+nums2[j] ,i+1 ,j});
            }
            if(j+1<m && !v.count({i,j+1})){
                v.insert({i,j+1});
                pq.push({nums1[i]+nums2[j+1] ,i ,j+1});
            }
        }

        return res;
    }
};