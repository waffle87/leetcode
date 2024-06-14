# 938. Range Sum of BST

"""
given the 'root' of a binary search tree and two integers 'low' and 'high',
return the sum of values of all nodes with a value in the inclusive range
'(low, high)'
"""

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def rangeSumBST(self, root, low, high):
        """
        :type root: TreeNode
        :type low: int
        :type high: int
        :rtype: int
        """
        def dfs(node):
            if not node:
                return 0
            
            current_val = 0
            if low <= node.val <= high:
                current_val = node.val
            
            left_sum = dfs(node.left)
            right_sum = dfs(node.right)
            
            return current_val + left_sum + right_sum
        
        return dfs(root)

if __name__ == "__main__":
    obj = Solution()
    print(obj.rangeSumBST(root = [10,5,15,3,7,null,18], low = 7, high = 15)) # expect: 15
    print(obj.rangeSumBST(root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10)) # expect: 23
