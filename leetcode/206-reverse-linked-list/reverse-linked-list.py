# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        if not head or not head.next:
            return head

        a = head
        b = head.next
        c = head.next.next

        a.next = None  

        while c:
            b.next = a
            a = b
            b = c
            c = c.next

        b.next = a

        return b
