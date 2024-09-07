# 1367. Linked List in Binary Tree

"""
given a binary tree 'root' and a linked list with 'head' as the first node.
return true if all the elements in the linked list starting from the 'head'
correspond to some downward path connected in the binary tree otherwise
return false. in this context downward path means a path that starts at some
node and goes downwards.
"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def isSubPath(self, head, root):
        """
        :type head: ListNode
        :type root: TreeNode
        :rtype: bool
        """

        def dfs(head, root):
            if not head:
                return True
            if not root:
                return False
            return root.val == head.val and (
                dfs(head.next, root.left) or dfs(head.next, root.right)
            )

        if not head:
            return True
        if not root:
            return False
        return (
            dfs(head, root)
            or self.isSubPath(head, root.left)
            or self.isSubPath(head, root.right)
        )


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.isSubPath(
            head=[4, 2, 8],
            root=[
                1,
                4,
                4,
                None,
                2,
                2,
                None,
                1,
                None,
                6,
                8,
                None,
                None,
                None,
                None,
                1,
                3,
            ],
        )
    )
    print(
        obj.isSubPath(
            head=[1, 4, 2, 6],
            root=[
                1,
                4,
                4,
                None,
                2,
                2,
                None,
                1,
                None,
                6,
                8,
                None,
                None,
                None,
                None,
                1,
                3,
            ],
        )
    )
