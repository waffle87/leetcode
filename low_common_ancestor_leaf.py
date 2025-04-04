# 1123. Lowest Common Ancestor of Deepest Leaves
import leetcode

"""
given the 'root' of a binary tree, return the lowest common ancestor of its
deepest leaves. recall that the node of a binary tree is a leaf if and only
if it has no children, the depth of the root of the tree is 0. if the depth
of a node is 'd', the depth of each of its children is 'd + 1'. and the
lowest common ancestor of a set 's' is the node 'a' with the largest depth
such that every node in 's' is in the subtree with root 'a'.
"""


class Solution(object):
    def lcaDeepestLeaves(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """

        def depth(node):
            if not node:
                return 0
            return max(depth(node.left), depth(node.right)) + 1

        def dfs(node, m, n):
            if not node:
                return None
            if m - 1 == n:
                return node
            l = dfs(node.left, m, n + 1)
            r = dfs(node.right, m, n + 1)
            if l and r:
                return node
            return l if l else r

        m = depth(root)
        return dfs(root, m, 0)


if __name__ == "__main__":
    obj = Solution()
    r1 = leetcode.treenode_build(root=[3, 5, 1, 6, 2, 0, 8, None, None, 7, 4])
    r2 = leetcode.treenode_build(root=[1])
    r3 = leetcode.treenode_build(root=[0, 1, 3, None, 2])
    print(obj.lcaDeepestLeaves(r1))
    print(obj.lcaDeepestLeaves(r2))
    print(obj.lcaDeepestLeaves(r3))
