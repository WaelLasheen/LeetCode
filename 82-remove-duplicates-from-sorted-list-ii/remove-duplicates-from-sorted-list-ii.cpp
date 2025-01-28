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
    ListNode* deleteDuplicates(ListNode* head) { 
        head = deleteDuplicatesFromHead(head);
        ListNode* it=head;
        while(it){
            it->next = deleteDuplicatesFromHead(it->next);
            it = it->next;
        }

        return head;
    }

private:
    ListNode* deleteDuplicatesFromHead(ListNode*& head) {
        // remove duplicates from head 
        ListNode* it = head;
        int diff=0;
        while(it){
            if(it->val != head->val){
                if(diff==1){
                    break;
                }
                else{
                    head = it;
                    diff=0;
                }
            }

            it = it->next;
            diff++;
        }
        if(!it && diff !=1){
            return NULL;
        }

        return head;
    }
};