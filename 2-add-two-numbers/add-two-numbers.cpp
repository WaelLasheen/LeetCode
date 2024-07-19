class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(); // Create a new node for the result
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* current = l3; // Pointer to track the current node in the result list
        int carry = 0;

        while (h1 || h2 || carry) {
            int sum = carry;

            if (h1) {
                sum += h1->val;
                h1 = h1->next;
            }

            if (h2) {
                sum += h2->val;
                h2 = h2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10); // Create a new node with the digit sum % 10
            current = current->next; // Move the current pointer to the next node
        }

        return l3->next; // Skip the dummy head node
    }
};
