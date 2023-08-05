# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        p1 = list1
        p2 = list2
        x1=list()
        while p1:
            x1.append(p1.val)
            p1=p1.next
        x2=list()
        while p2:
            x2.append(p2.val)
            p2=p2.next
        x=x1+x2
        x.sort()
        new = ListNode()
        p = new
       
        for i in range (len(x)):
            
            
            temp = ListNode(x[i])
           
            new.next = temp
            new = new.next
           
        return p.next
        
