class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode* list1 = head1;
        ListNode* list2 = head2;

        ListNode* result = new ListNode();
        ListNode* temp = result;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } 
            else {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        while (list1) {
            temp->next = list1;
            list1 = list1->next;
            temp = temp->next;
        }

        while (list2) {
            temp->next = list2;
            list2 = list2->next;
            temp = temp->next;
        }

        return result->next;
    }
};