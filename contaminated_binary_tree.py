# 1261. Find Elements in a Contaminated Binary Tree

"""
given a binary tree with the following rules: 'root.val == 0', for any
'TreeNode': if 'TreeNode.val' has a value 'x' and 'TreeNode.left != null'
then 'TreeNode.left.val == 2  x + 1', and if 'TreeNode.val' has a value 'x'
and 'TreeNode.right != null', then 'TreeNode.right.val = 2  x + 2'. now the
binary tree is contaminated which means all 'TreeNode.val' have been changed
to -1. implemented the 'FindElements' class: 'findElementsCreate':
initialises the object with a contaminated tree and recovers it. 'bool
find(int target)' returns 'true' if the 'target' value exists in the
recovered binary tree.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class FindElements(object):
    def __init__(self, root):
        """
        :type root: Optional[TreeNode]
        """

        def recover(root, val):
            return (
                root
                and {val}
                | recover(root.left, 2 * val + 1)
                | recover(root.right, 2 * val + 2)
                or set()
            )

        self.find = recover(root, 0).__contains__


if __name__ == "__main__":
    r1 = TreeNode(-1)
    r1.left = None
    r1.right = TreeNode(-1)
    r2 = TreeNode(-1)
    r2.left = TreeNode(-1)
    r2.right = TreeNode(-1)
    r2.left.left = TreeNode(-1)
    r2.left.right = TreeNode(-1)
    r3 = TreeNode(-1)
    r3.left = None
    r3.right = TreeNode(-1)
    r3.right.left = TreeNode(-1)
    r3.right.right = None
    r3.right.left.left = TreeNode(-1)
    r3.right.left.right = None
    o1 = FindElements(r1)
    o2 = FindElements(r2)
    o3 = FindElements(r3)
    print(o1.find(1))
    print(o1.find(2))
    print(o2.find(1))
    print(o2.find(3))
    print(o2.find(5))
    print(o3.find(2))
    print(o3.find(3))
    print(o3.find(4))
    print(o3.find(5))
