# 2807. Insert Greatest Common Divisors in Linked List

"""
given the head of a linked list 'head', in which each node contains an
integer value. between every pair of adjacent nodes, insert a new node with a
value equal to the greatest common divisor. return the linked list after
insertion. the greatest common divisor of two numbers is the largest positive
integer that evenly divides both numbers.
"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def gcd(self, a, b):
        while b:
            a, b = b, a % b
        return a

    def insertGreatestCommonDivisors(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if not head or not head.next:
            return head
        node1 = head
        while node1.next:
            node2 = node1.next
            r = self.gcd(node1.val, node2.val)
            new = ListNode(r)
            node1.next = new
            new.next = node2
            node1 = node2
        return head


if __name__ == "__main__":
    obj = Solution()
    print(obj.insertGreatestCommonDivisors(head=[18, 6, 10, 3]))
    print(obj.insertGreatestCommonDivisors(head=[7]))
