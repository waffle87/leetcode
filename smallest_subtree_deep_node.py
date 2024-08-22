# 865. Smallest Subtree with all the Deepest Nodes

"""
given the 'root' of a binary tree, the depth of each node is the shortest
distance to the root. return the smallest subtree such that it contains all
the deepest nodes in the original tree. a node is called the deepest if it
has the largest depth possible among any node in the entire tree. the
subbtree of a node is a tree consisting of that node, plus the set of all
descendants of that node
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def subtreeWithAllDeepest(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """

        def dfs(root):
            if not root:
                return 0, None
            l, r = dfs(root.left), dfs(root.right)
            if l[0] > r[0]:
                return l[0] + 1, l[1]
            elif l[0] < r[0]:
                return r[0] + 1, r[1]
            else:
                return l[0] + 1, root

        return dfs(root)[1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.subtreeWithAllDeepest(root=[3, 5, 1, 6, 2, 0, 8, None, None, 7, 4]))
    print(obj.subtreeWithAllDeepest(root=[1]))
    print(obj.subtreeWithAllDeepest(root=[0, 1, 3, None, 2]))
