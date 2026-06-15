# 2095. Delete the Middle Node of a Linked List
from typing import Optional

from leetcode import ListNode, listnode_build, listnode_print

"""
you are given the 'head' of a linked list. delete the middle node, and return
the 'head' of the modified linked list. the middle of a linked list of size
'n' is the 'floor(n / 2)'th node from the start using 0-based indexing, where
'floor(x)' denotes the largest integer less than or equal to 'x'.
"""


class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = ListNode(0)
        prev.next = head
        slow = prev
        fast = head
        while fast != None and fast.next != None:
            slow = slow.next
            fast = fast.next.next

        slow.next = slow.next.next
        return prev.next


if __name__ == "__main__":
    obj = Solution()
    h1 = listnode_build(vals=[1, 3, 4, 7, 1, 2, 6])
    h2 = listnode_build(vals=[1, 2, 3, 4])
    h3 = listnode_build(vals=[2, 1])
    r1 = obj.deleteMiddle(h1)
    r2 = obj.deleteMiddle(h2)
    r3 = obj.deleteMiddle(h3)
    listnode_print(r1)
    listnode_print(r2)
    listnode_print(r3)
