# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        p=head
        if not head:
            return head
        x=list()
        while p:
            x.append(p.val)
            p=p.next
        new = ListNode()
        a = new
       
        for i in range (len(x)-1,-1,-1):
            
            
            temp = ListNode(x[i])
           
            new.next = temp
            new = new.next
           
        return a.next
