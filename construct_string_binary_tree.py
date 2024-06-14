# 606. Construct String from Binary Tree

"""
given the root of a binary tree, construct a string consisting of parenthesis
and integers from a binary tree with the preorder traversal way, and return
it. omit all the empty parenthesis pairs that do not affect the one-to-one
mapping relationship between the string and the original binary tree
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def tree2str(self, root):
        """
        :type root: TreeNode
        :rtype: str
        """

        def generate_paren_str(self, node):
            if not node:
                return ""

            left_str = generate_paren_str(node.left)
            right_str = generate_paren_str(node.right)
            level_str = f"{node.val}({left_str})({right_str})"
            return level_str

        def strip_excessive_parenthesis(self, parenthesis_str):
            final_str = []
            n = len(parenthesis_str)
            i = 0
            while i < n:
                if i + 4 <= n and parenthesis_str[i : i + 4] == "()()":
                    i += 4
                    continue

                if i + 3 <= n and (
                    parenthesis_str[i : i + 3] == "())"
                    or parenthesis_str[i : i + 3] == ")()"
                ):
                    i += 2
                    continue

                final_str.append(parenthesis_str[i])
                i += 1
            return "".join(final_str)

        return strip_excessive_parenthesis(generate_paren_str(root))


if __name__ == "__main__":
    obj = Solution()
    print(obj.tree2str(root=[1, 2, 3, 4]))  # expect: "1(2(4))(3)"
