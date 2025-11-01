# 3217. Delete Nodes From Linked List Present in Array
from leetcode import ListNode, listnode_build

"""
you are given an array of integers 'nums' and the 'head' of a linked list.
return the 'head' of the modified linked list after removing all nodes from
the linked list that have a value that exists in 'nums'.
"""


class Solution(object):
    def modifiedList(self, nums, head):
        """
        :type nums: List[int]
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        map = set(nums)
        tmp = ListNode(0, head)
        prev, curr = tmp, head
        curr = head
        while curr:
            if curr.val in map:
                prev.next = curr.next
            else:
                prev = prev.next
            curr = curr.next
        return tmp.next


if __name__ == "__main__":
    obj = Solution()
    n1, h1 = [1, 2, 3], listnode_build(vals=[1, 2, 3, 4, 5])
    n2, h2 = [1], listnode_build(vals=[1, 2, 1, 2, 1, 2])
    n3, h3 = [5], listnode_build(vals=[1, 2, 3, 4])
    print(obj.modifiedList(n1, h1))
    print(obj.modifiedList(n2, h2))
    print(obj.modifiedList(n3, h3))
