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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        sort(nums.begin(),nums.end());

        while(head && binary_search(nums.begin(),nums.end(),head->val)){
            head = head->next;
        }

        ListNode *it=head;
        while(it){
            while(it->next && binary_search(nums.begin(),nums.end(),it->next->val)){
                it-> next = it->next->next;
            }
            
            it = it->next;
        }

        return head;
    }
};