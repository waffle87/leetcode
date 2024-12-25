# 515. Find Largest Value in Each Tree Row
import leetcode

"""
given the 'root' of a binary tree, return an array of the largest value in
each row of the tree (0-indexed).
"""


class Solution(object):
    def largestValues(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        ans, row = [], [root]
        while any(row):
            ans.append(max(node.val for node in row))
            row = [child for node in row for child in (node.left, node.right) if child]
        return ans


if __name__ == "__main__":
    obj = Solution()
    r1i = [1, 3, 2, 5, 3, None, 9]
    r2i = [1, 2, 3]
    r1 = leetcode.list_to_tree(r1i)
    r2 = leetcode.list_to_tree(r2i)
    print(obj.largestValues(r1))
    print(obj.largestValues(r2))
