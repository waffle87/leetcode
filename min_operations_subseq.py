# 1713. Minimum Operations to Make a Subsequence
from bisect import bisect_left

"""
given an array 'target' that consists of distinct integers and another
integer array 'arr' that can have duplicates. in one operatioin, you can
insert any integer at any position in 'arr'. note that you can inser the
integer at the very beginning or end of the array. return the minimum number
of operations needed to make 'target' a subsequence of 'arr'. a subsequence
of anarray is a new array generated from the original array by deleting some
elements (possibly none) without changing the remaining elements.
"""


class Solution(object):
    def minOperations(self, target, arr):
        """
        :type target: List[int]
        :type arr: List[int]
        :rtype: int
        """
        dic = {num: i for i, num in enumerate(target)}
        a = []
        for num in arr:
            if num in dic:
                a.append(dic[num])
        return len(target) - self.len_list(self, nums)

    def len_list(self, nums):
        if not nums:
            return 0
        piles = []
        for n in nums:
            idx = bisect_left(piles, n)
            if idx == len(piles):
                piles.append(num)
            else:
                piles[idx] = n
        return len(piles)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations(target=[5, 1, 3], arr=[9, 4, 2, 3, 4]))
    print(obj.minOperations(target=[6, 4, 8, 1, 3, 2], arr=[4, 7, 6, 2, 3, 8, 6, 1]))
