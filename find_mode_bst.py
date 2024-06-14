# 501. Find Mode in Binary Search Tree

"""
given the 'root' of a binary search tree with duplicates, return all the
'modes(s)' (ie. the most frequently occured element in it). if the tree has
more than one mode, return them in any order.
"""


class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    prev = None
    max_cnt = 0
    curr_cnt = 0
    ans = []

    def dfs(self, node):
        if not node:
            return
        self.dfs(node.left)
        self.curr_cnt = 1 if node.val != self.prev else self.curr_cnt + 1
        if self.curr_cnt == self.max_cnt:
            self.ans.append(node.val)
        elif self.curr_cnt > self.max_cnt:
            self.ans = [node.val]
            self.max_cnt = self.curr_cnt
        self.prev = node.val
        self.dfs(node.right)

    def findMode(self, root):
        self.dfs(root)
        return self.ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.findMode([1, None, 2, 2]))  # expect: 2
    print(obj.findMode([0]))  # expect: 0
