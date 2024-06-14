# 2441. Largest Positive Integer That Exists With Its Negative

"""
given an integer array 'nums'that does not contain any zeros, find the
largest positive integer 'k' such that '-k' also exists in the array. return
the positive integer 'k'. if there is no such integer, return -1;
"""


class Solution(object):
    def findMaxK(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        left, right = 0, len(nums) - 1
        max_k = float("-inf")
        while left < right:
            if nums[left] + nums[right] == 0:
                max_k = max(max_k, nums[right])
                left += 1
                right -= 1
            elif nums[left] + nums[right] < 0:
                left += 1
            else:
                right -= 1
        return max_k if max_k != float("-inf") else -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.findMaxK([-1, 2, -3, 3]))
    print(obj.findMaxK([-1, 10, 6, 7, -7, 1]))
    print(obj.findMaxK([-10, 8, 6, 7, -2, -3]))
