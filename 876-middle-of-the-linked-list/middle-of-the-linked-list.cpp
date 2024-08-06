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
    ListNode* middleNode(ListNode* head) {
        ListNode *sb1=head, *sb2=head;  // one jump by one step and other by two
        while(sb2 && sb2->next){
            sb1 = sb1->next;
            sb2 = sb2->next->next;
        }

        return sb1;
    }
};