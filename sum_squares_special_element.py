# 2778. Sum of Squares of Special Elements

"""
you are given a 1-indexed integer array 'nums' of length 'n'. an element
'nums[i]' of 'nums' is called special if 'i' divides 'n'. return the sum of
the squares of all special elements of 'nums'.
"""


class Solution:
    def sumOfSquares(self, nums: list[int]) -> int:
        cnt, n = 0, len(nums)
        for i in range(n):
            if n % (i + 1) == 0:
                cnt += nums[i] ** 2
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.sumOfSquares(nums=[1, 2, 3, 4]))
    print(obj.sumOfSquares(nums=[2, 7, 1, 19, 18, 3]))
