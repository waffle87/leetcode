# 3217. Delete Nodes From Linked List Present in Array

"""
you are given an array of integers 'nums' and the 'head' of a linked list.
return the 'head' of the modified linked list after removing all nodes from
the linked list that have a value that exists in 'nums'.
"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def modifiedList(self, nums, head):
        """
        :type nums: List[int]
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        nums = set(nums)
        while head.val in nums:
            head = head.next
        ans = ListNode(head.val, head)
        while head and head.next:
            if head.next.val in nums:
                head.next = head.next.next
            else:
                head = head.next
        return ans.next


if __name__ == "__main__":
    obj = Solution()
    print(obj.modifiedList(nums=[1, 2, 3], head=[1, 2, 3, 4, 5]))
    print(obj.modifiedList(nums=[1], head=[1, 2, 1, 2, 1, 2]))
    print(obj.modifiedList(nums=[5], head=[1, 2, 3, 4]))
