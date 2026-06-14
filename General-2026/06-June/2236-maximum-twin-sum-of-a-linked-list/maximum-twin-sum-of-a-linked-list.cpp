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
    int pairSum(ListNode* head) {
        ListNode *s1=head,*s2=head;
        stack<int>h1;
        while(s2){
            h1.push(s1->val);
            s1=s1->next;
            s2=s2->next->next;
        }
        int out=INT_MIN;
        while(s1){
            int s=h1.top()+s1->val;
            out=max(out,s);
            h1.pop();
            s1=s1->next;
        }
        return out;
    }
};