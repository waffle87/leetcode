# 1530. Number of Good Leaf Nodes Pairs
from collections import defaultdict

"""
you are given the 'root' of a binary tree and an integer 'distance' a pair of
two different leaf nodes of a binary tree is said to be good if the length of
the shortest path between them is less than or equal to 'distance'. return
the number of good leaf node pairs in the tree.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def cntPairs(self, root, distance):
        """
        :type root: TreeNode
        :type distance: int
        :rtype: int
        """
        graph = defaultdict(list)

        def dfs(node, par=None):
            if node:
                graph[node].append(par)
                graph[par].append(node)
                dfs(node.left, node)
                dfs(node.right, node)

        dfs(root)
        leaves = []
        for node in graph.keys():
            if node and not node.left and not node.right:
                leaves.append(node)
        cnt = 0
        for leaf in leaves:
            queue = [(leaf, 0)]
            seen = set(queue)
            while queue:
                node, length = queue.pop(0)
                if length > distance:
                    break
                if node:
                    for nei in graph[node]:
                        if nei not in seen:
                            seen.add(nei)
                            queue.append((nei, length + 1))
                    if (
                        node != leaf
                        and not node.left
                        and not node.right
                        and length <= distance
                    ):
                        cnt += 1
        return cnt // 2


if __name__ == "__main__":
    obj = Solution()
    print(obj.cntPairs(root=[1, 2, 3, null, 4], distance=3))
