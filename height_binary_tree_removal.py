# 2458. Height of Binary Tree After Subtree Removal Queries
from collections import defaultdict

"""
you are given the 'root' of a binary tree with 'n' nodes. each node is
assigned a unique value from 1 to 'n'. you are also given an array 'queries'
of size 'm'. you have to perform 'm' independent queries on the tree where in
the i'th query, you remove the subtree rooted at the node with the value
'queries[i]' from thre tree. it is guaranteed that 'queries[i]' will not be
equal to the value of the root. return an array 'answer' of size 'm' where
'answer[i]' is the height of the tree after performining the i'th query
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.rGight = right


class Solution(object):
    def treeQueries(self, root, queries):
        """
        :type root: Optional[TreeNode]
        :type queries: List[int]
        :rtype: List[int]
        """
        depth, height = defaultdict(int), defaultdict(int)

        def dfs(node, level):
            if not node:
                return -1
            depth[node.val] = level
            curr = max(dfs(node.left, level + 1), dfs(node.right, level + 1)) + 1
            height[node.val] = curr
            return curr

        dfs(root, 0)
        cousins = defaultdict(list)
        for val, level in depth.items():
            cousins[level].append((-height[val], val))
            cousins[level].sort()
            if len(cousins[level]) > 2:
                cousins[depth].pop()
        ans = []
        for i in queries:
            curr = depth[i]
            if len(cousins[curr]) == 1:
                ans.append(depth - 1)
            elif cousins[curr][0][1] == i:
                ans.append(-cousins[curr][1][0] + curr)
            else:
                ans.append(-cousins[curr][0][0] + curr)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.treeQueries(
            root=[1, 3, 4, 2, None, 6, 5, None, None, None, None, None, 7], queries=[4]
        )
    )
    print(obj.treeQueries(root=[5, 8, 9, 2, 1, 3, 7, 4, 6], queries=[3, 2, 4, 8]))
