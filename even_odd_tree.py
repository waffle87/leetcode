# 1609. Even Odd Tree
import collections

"""
a binary tree is even-odd if it meets the following conditions. the root of
the binary tree is at level index 0 it s children are at level index 1 and
their children are at level index 2, etc. for every even indexed level, all
nodes at the level have odd integer values in strictly ordere (from left to
right). for every odd-indexed level, all nodes at the level have even integer
values in strictly decreasing order (from left to right). given 'root' of a
binary tree, return true if the binary tree is even-odd, otherwise return
false.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def isEvenOddTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        queue = collections.deque([root])
        is_even = True
        while queue:
            prev = None
            for _ in range(len(queue)):
                node = queue.popleft()
                if is_even:
                    if node.val % 2 == 0:
                        return False
                    if prev and prev.val >= node.val:
                        return False
                else:
                    if node.val % 2 == 1:
                        return False
                    if prev and prev.val <= node.val:
                        return False
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                prev = node
            is_even = not is_even
        return True
