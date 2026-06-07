# 2196. Create Binary Tree From Descriptions
from leetcode import TreeNode, treenode_print

"""
you are given a 2d integer array 'descriptions' where 'descriptions[i] =
[parent_i, child_i, isleft_i]' indicates that 'parent_i' is the parent of
'child_i', in a binary tree of unique values. construct the binary tree
described by 'descriptions' and return its root. the test cases will be
generated such that the binary tree is valid.
"""


class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        children, map = set(), {}
        for parent, child, left in descriptions:
            node_parent = map.setdefault(parent, TreeNode(parent))
            node_child = map.setdefault(child, TreeNode(child))
            if left:
                node_parent.left = node_child
            else:
                node_parent.right = node_child
            children.add(child)
        root = (set(map) - set(children)).pop()
        return map[root]


if __name__ == "__main__":
    obj = Solution()
    cbt1 = obj.createBinaryTree(
        descriptions=[
            [20, 15, 1],
            [20, 17, 0],
            [50, 20, 1],
            [50, 80, 0],
            [80, 19, 1],
        ]
    )
    cbt2 = obj.createBinaryTree(descriptions=[[1, 2, 1], [2, 3, 0], [3, 4, 1]])
    treenode_print(cbt1)
    treenode_print(cbt2)
