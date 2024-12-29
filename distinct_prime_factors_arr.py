# 2521. Distinct Prime Factors of Product of Array
from math import sqrt

"""
given an array of positive integers 'nums', return the number of distinct
prime factors in the product of the element of 'nums'. note that a number
greater than 1 is called prime if it is divisible by only 1 and itself. an
integer 'val1' is a factor of another integer 'val2' if 'val2 / val1' is an
integer
"""


class Solution(object):
    def distinctPrimeFactors(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        arr = []
        for i in range(len(nums)):
            root = int(sqrt(nums[i]))
            for num in range(2, root + 1):
                if nums[i] % num == 0:
                    arr.append(num)
                    while nums[i] % num == 0:
                        nums[i] = nums[i] // num
            if nums[i] >= 2:
                arr.append(nums[i])
        arr = set(arr)
        return len(arr)


if __name__ == "__main__":
    obj = Solution()
    print(obj.distinctPrimeFactors(nums=[2, 4, 3, 7, 10, 6]))
    print(obj.distinctPrimeFactors(nums=[2, 4, 8, 16]))
