# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        p=q=head
        x=list()
        while p:
            x.append(p.val)
            p=p.next
        i=1
        if len(x)%2==0:
            print("hi")
            k=(len(x)//2)+1
            while i < k:
                q=q.next
                i+=1
            return q
        else:
            
            k=(len(x)//2)+1
            print(len(x))
            while i < k:
                print("hi")
                q=q.next
                i+=1
            return q
