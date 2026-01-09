# 865. Smallest Subtree with all the Deepest Nodes
import leetcode

"""
given the 'root' of a binary tree, the depth of each node is the shortest
distance to the root. return the smallest subtree such that it contains all
the deepest nodes in the original tree. a node is called the deepest if it
has the largest depth possible among any node in the entire tree. the
subbtree of a node is a tree consisting of that node, plus the set of all
descendants of that node
"""


class Solution(object):
    def subtreeWithAllDeepest(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """

        def dfs(node):
            if not node:
                return 0, None
            ld, ln = dfs(node.left)
            rd, rn = dfs(node.right)
            if ld > rd:
                return ld + 1, ln
            if rd > ld:
                return rd + 1, rn
            return ld + 1, node

        return dfs(root)[1]


if __name__ == "__main__":
    obj = Solution()
    r1 = leetcode.treenode_build(vals=[3, 5, 1, 6, 2, 0, 8, None, None, 7, 4])
    r2 = leetcode.treenode_build(vals=[1])
    r3 = leetcode.treenode_build(vals=[0, 1, 3, None, 2])
    print(obj.subtreeWithAllDeepest(r1))
    print(obj.subtreeWithAllDeepest(r2))
    print(obj.subtreeWithAllDeepest(r3))
