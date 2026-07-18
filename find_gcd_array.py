# 1979. Find Greatest Common Divisor of Array

"""
given an integer array 'nums', return the greatest common divisor of the
smallest number and largest in 'nums'. the greatest common divisor of two
numbers is the largest positive integer that evenly divides both numbers.
"""


class Solution:
    def findGCD(self, nums: List[int]) -> int:
        a, b = min(nums), max(nums)
        while a:
            a, b = b % a, a
        return b


if __name__ == "__main__":
    obj = Solution()
    print(obj.findGCD(nums=[2, 5, 6, 9, 10]))
    print(obj.findGCD(nums=[7, 5, 6, 8, 3]))
    print(obj.findGCD(nums=[3, 3]))
