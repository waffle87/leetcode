# 1509. Minimum Difference Between Largest and Smallest Value in Three Moves

"""
given an integer array 'nums'. in one move you can choose one element of
'nums' and change it to any value. return the minimum difference between the
largest and smallest value of 'nums' after performing at most three moves.
"""


class Solution(object):
    def minDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        return min(b - a for a, b in zip(nums[:4], nums[-4:]))


if __name__ == "__main__":
    obj = Solution()
    print(obj.minDifference(nums=[5, 3, 2, 4]))
    print(obj.minDifference(nums=[1, 5, 0, 10, 14]))
    print(obj.minDifference(nums=[3, 100, 20]))
