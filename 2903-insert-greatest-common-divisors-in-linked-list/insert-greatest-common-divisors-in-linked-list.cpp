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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *it=head;
        while(it->next){
            int gcd = __gcd(it->val ,it->next->val);
            ListNode * gcdNode = new ListNode(gcd);
            gcdNode->next = it->next;
            it->next = gcdNode;
            it = it->next->next;
        }

        return head;
    }
};