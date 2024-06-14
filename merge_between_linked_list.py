# 1669. Merge In Between Linked Lists

"""
given two linked lists 'l1' and 'l2' of sizes 'n' and 'm' respectively.
remove 'l1' nodes from the a'th node to the b'th node, and put 'l2' in their
place. the blue edges and nodes in the following figure indicate the result.
"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def mergeInBetween(self, list1, a, b, list2):
        """
        :type list1: ListNode
        :type a: int
        :type b: int
        :type list2: ListNode
        :rtype: ListNode
        """
        start, end = None, list1
        for i in range(b):
            if i == a - 1:
                start = end
            end = end.next
        start.next = list2
        while list2.next:
            list2 = list2.next
        list2.next = end.next
        end.next = None
        return list1


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.mergeInBetween(
            list1=[10, 1, 13, 6, 9, 5], a=3, b=4, list2=[1000000, 1000001, 1000002]
        )
    )
    print(
        obj.mergeInBetween(
            list1=[0, 1, 2, 3, 4, 5, 6],
            a=2,
            b=5,
            list2=[1000000, 1000001, 1000002, 1000003, 1000004],
        )
    )
