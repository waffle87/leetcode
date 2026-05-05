# 61. Rotate List
from typing import Optional

from leetcode import ListNode, listnode_build

"""
given the 'head' of a linked list, rotate the list to the rigt by 'k' places.
"""


class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        curr = head
        len = 1
        while curr.next:
            curr = curr.next
            len += 1
        curr.next = head
        k = k % len
        print(k)
        print(len)
        for i in range(len - k):
            curr = curr.next
        head = curr.next
        curr.next = None
        return head


if __name__ == "__main__":
    obj = Solution()
    h1 = listnode_build(vals=[1, 2, 3, 4, 5])
    h2 = listnode_build(vals=[0, 1, 2])
    print(obj.rotateRight(h1, k=2))
    print(obj.rotateRight(h1, k=4))
