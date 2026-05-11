# 2553. Separate the Digits in an Array
from typing import List

"""
given an array of positive integers 'nums', return an array 'answer' that
consists of the digits of each integer in 'nums'. to separate the digits of
an integer is to get all the digits it has in the same order.
"""


class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        res = []
        for x in nums:
            tmp = []
            while x > 0:
                tmp.append(x % 10)
                x //= 10
            res.extend(tmp[::-1])
        return res


if __name__ == "__main__":
    obj = Solution()
    print(obj.separateDigits(nums=[13, 25, 83, 77]))
    print(obj.separateDigits(nums=[7, 1, 3, 9]))
