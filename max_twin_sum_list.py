# 2130. Maximum Twin Sum of a Linked List
from leetcode import ListNode, listnode_build

"""
in a linked-list of size 'n', where 'n' is even, the i'th node (0-indexed) of
the linked list is known as the twin of the 'n - 1 - i' node, if 0 <= i <= (n
/ 2) - 1. for example, if 'n = 4', then node 0 is the twin of node 3, and
node 1 is the twin node of node 2. these are the only nodes with twins for 'n
= 4'. the twin sum is defined as the sum of a node and its twin. given the
'head' of a linked list with even length, return the maximum twin sum of the
linked list.
"""


class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        slow, fast, ans = head, head, 0
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        curr, prev = slow, None
        while curr:
            curr.next, prev, curr = prev, curr, curr.next
        while prev:
            ans = max(ans, head.val + prev.val)
            prev = prev.next
            head = head.next
        return ans


if __name__ == "__main__":
    obj = Solution()
    h1 = listnode_build(vals=[5, 4, 2, 1])
    h2 = listnode_build(vals=[4, 4, 2, 3])
    h3 = listnode_build(vals=[1, 100000])
    print(obj.pairSum(h1))
    print(obj.pairSum(h2))
    print(obj.pairSum(h3))
