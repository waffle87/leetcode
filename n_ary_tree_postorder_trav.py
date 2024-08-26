# 590. N-ary Tree Postorder Traversal

"""
given the 'root' of an n-ary tree, return the postorder traversal of its
nodes' values. nary-tree input serialisation is represented in their level
order traversal. each group of children is separated by the None value.
"""


# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution(object):
    def postorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        ans = []
        if not root:
            return ans

        def dfs(root, ans):
            for child in root.children:
                dfs(child, ans)
            ans.append(root.val)

        dfs(root, ans)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.postorder(root=[1, None, 3, 2, 4, None, 5, 6]))
    print(
        root=[
            1,
            None,
            2,
            3,
            4,
            5,
            None,
            None,
            6,
            7,
            None,
            8,
            None,
            9,
            10,
            None,
            None,
            11,
            None,
            12,
            None,
            13,
            None,
            None,
            14,
        ]
    )
