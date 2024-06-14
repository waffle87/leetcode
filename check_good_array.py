# 1250. Check If It Is a Good Array

"""
given an array 'nums' of positive integers. your task is to select some
subset of 'nums', multiply each element by an integer and add all these
numbers. the array is said to be good if you can obtain a sum of 1 from the
array by any possible subset and multiplicand. return 'true' if the array is
good, otherwise return 'false'
"""


class Solution(object):
    def isGoodArray(self, nums):
        gcd = nums[0]
        for i in nums:
            while i:
                gcd, i = i, gcd % i
        return gcd == 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.isGoodArray([12, 5, 7, 23]))  # expect: True
    print(obj.isGoodArray([29, 6, 10]))  # expect: True
    print(obj.isGoodArray([3, 6]))  # expect: False
