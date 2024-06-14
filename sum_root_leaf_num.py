# 129. Sum Root to Leaf Numbers
from collections import deque

"""
given 'root' of binary tree containing digits 0-9 only. each root-to-leaf
pattern in the tree represents a number. eg. root-to-leaf path 1->2->3
represents the integer 123. return total sum of all root-to-leaf numbers.
test cases will fit in 32-bit integer. a leaf node is a node with no children
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def from_list(data):
    def create(it):
        val = next(it)
        return None if val is None else TreeNode(val)

    if not data:
        return None
    it = iter(data)
    root = TreeNode(next(it))
    nextlevel = [root]
    try:
        while nextlevel:
            level = nextlevel
            nextlevel = []
            for node in level:
                if node:
                    node.left = create(it)
                    node.right = create(it)
                    nextlevel += [node.left, node.right]
    except StopIteration:
        return root


class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        s, tot_sum = deque([(root, 0)]), 0
        while len(s):
            root, cur = s.pop()
            cur *= 10 + root.val
            if not root.left and not root.right:
                tot_sum += cur
            if root.right:
                s.append((root.right, cur))
            if root.left:
                s.append((root.left, cur))
        return tot_sum


if __name__ == "__main__":
    r1, r2 = Solution(), Solution()
    t1 = [1, 2, 3]
    t2 = [4, 9, 0, 5, 1]
    print(r1.sumNumbers(from_list(t1)))  # expect: 25
    print(r2.sumNumbers(from_list(t2)))  # expect: 1026
