# 217. Contains Duplicate

"""
given an integer array 'nums', return true if any value appears at least
twice in the array, and return false if every element is distinct
"""


class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        vis = {}
        for i in nums:
            if i in vis and vis[i] >= 1:
                return True
            vis[i] = vis.get(i, 0) + 1
        return False


if __name__ == "__main__":
    obj = Solution()
    print(obj.containsDuplicate(nums=[1, 2, 3, 1]))
    print(obj.containsDuplicate(nums=[1, 2, 3, 4]))
    print(obj.containsDuplicate(nums=[1, 1, 1, 3, 3, 4, 3, 2, 4, 2]))
