# 2870. Minimum Number of Operations to Make Array Empty
from collections import Counter

"""
you are given a 0-indexed array 'nums' consisting of positive integers. there
are two types of operations that you can apply on the array any number of
times. choose two elements with equal values and delete them from the array.
choose three elements with equal values and delete them from the array.
return the minimum number of operations required to make the array empty, or
-1 if it is not possible.
"""


class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ctr = Counter(nums)
        cnt = 0
        for i in ctr.values():
            if i == 1:
                return -1
            cnt += i // 3
            if i % 3:
                cnt += 1
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations(nums=[2, 3, 3, 2, 2, 4, 2, 3, 4]))  # expect: 4
    print(obj.minOperations(nums=[2, 1, 2, 2, 3, 3]))  # expect: -1
