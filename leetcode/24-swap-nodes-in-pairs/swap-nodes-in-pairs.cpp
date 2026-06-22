class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swap
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move to next pair
            prev = first;
        }

        return dummy.next;
    }
};