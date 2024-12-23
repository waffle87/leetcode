# 2471. Minimum Number of Operations to Sort a Binary Tree by Level
from collections import deque

"""
you are given the 'root' of a binary tree with unique values. in one
operation, you can choose any two nodes at the same level and swap their
values. return the minimum number of operations needed to make the values at
each level sorted in a strictly increasing order. the level of a node is the
number of edges along the path between it and the root node.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def minimumOperations(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """

        def dfs(i, idx, seen):
            if seen[i]:
                return 0
            seen[i] = True
            j = idx[i]
            return dfs(j, idx, seen) + 1

        q = deque()
        q.append(root)
        swaps = 0
        while q:
            n = len(q)
            arr = [0] * n
            for i in range(n):
                node = q.popleft()
                arr[i] = node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            idx = sorted(range(n), key=lambda x: arr[x])
            seen = [False] * n
            for i in range(n):
                if not seen[i]:
                    swaps += dfs(i, idx, seen) - 1
        return swaps


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.minimumOperations(
            root=[1, 4, 3, 7, 6, 8, 5, None, None, None, None, 9, None, 10]
        )
    )
    print(obj.minimumOperations(root=[1, 3, 2, 7, 6, 5, 4]))
    print(obj.minimumOperations(root=[1, 2, 3, 4, 5, 6]))
