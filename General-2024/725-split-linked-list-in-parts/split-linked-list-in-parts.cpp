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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        ListNode *it=head;
        while(it){
            len++;
            it=it->next;
        }
        int rem = len%k;
        len /=k;

        vector<ListNode*> res(k);
        it = head;
        int i=0;
        while(rem--){
            res[i++]=it;
            for(int j=0;j<len;j++){
                it = it->next;
            }
            ListNode* next =it->next;
            it->next=NULL;
            it = next;
        }

        while(it){
            res[i++]=it;
            for(int j=0;j<len-1;j++){
                it = it->next;
            }
            ListNode* next =it->next;
            it->next=NULL;
            it = next;
        }

        return res;
    }
};