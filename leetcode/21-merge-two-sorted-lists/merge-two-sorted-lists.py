# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1, list2):
        head = ListNode(0)
        a = head

        def solve(l1, l2):
            nonlocal a

            if not l1:
                a.next = l2
                return

            if not l2:
                a.next = l1
                return

            if l1.val <= l2.val:
                a.next = l1
                l1 = l1.next
            else:
                a.next = l2
                l2 = l2.next

            a = a.next

            return solve(l1, l2)

        solve(list1, list2)
        
        return head.next