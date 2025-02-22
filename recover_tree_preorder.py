# 1028. Recover a Tree From Preorder Traversal
from leetcode import TreeNode
from re import findall

"""
we run a preorder depth-first search (dfs) on the 'root' of a binary tree. at
each node in this traversal, we output 'D' dashes (where 'D' is the depth of
this node), then we output the value of this node. if the depth of a node is
'D' the depth of its immediate child is 'D + 1'. the depth of the 'root' node
is '0'. if a node has only one child, that child is guaranteed to be the left
child. given the output 'traversal' of this traversal, recover the tree and
return its root.
"""


class Solution(object):
    def recoverFromPreorder(self, traversal):
        """
        :type traversal: str
        :rtype: Optional[TreeNode]
        """
        nodes = [
            (len(node[1]), int(node[2])) for node in findall("((-*)(\d+))", traversal)
        ][::-1]

        def recover(depth):
            if not nodes or depth != nodes[-1][0]:
                return None
            node = TreeNode(nodes.pop()[1])
            node.left = recover(depth + 1)
            node.right = recover(depth + 1)
            return node

        return recover(0)


if __name__ == "__main__":
    obj = Solution()
    print(obj.recoverFromPreorder(traversal="1-2--3--4-5--6--7"))
    print(obj.recoverFromPreorder(traversal="1-2--3---4-5--6---7"))
    print(obj.recoverFromPreorder(traversal="1-401--349---90--88"))
