/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res (m,vector<int>(n,-1));
        ListNode *it=head;

        int top=0 ,bottom=m-1 ,left=0 ,right=n-1;
        while(it){
            // left to right
            for(int i=left;i<= right;i++){
                res[top][i] = it->val;
                it = it->next;
                if(!it){
                    return res;
                }
            }
            top++;

            // top to bottom
            for(int i=top;i<= bottom;i++){
                res[i][right] = it->val;
                it = it->next;
                if(!it){
                    return res;
                }
            }
            right--;

            // right to left
            for(int i=right;i>= left;i--){
                res[bottom][i] = it->val;
                it = it->next;
                if(!it){
                    return res;
                }
            }
            bottom--;

            // bottom to top
            for(int i=bottom;i>= top;i--){
                res[i][left] = it->val;
                it = it->next;
                if(!it){
                    return res;
                }
            }
            left++;
        }

        return res;
    }
};