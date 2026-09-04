# 3903. Smallest Stable Index I

"""
you are given an integer array 'nums' of length 'n' and an integer 'k'. for
each index 'i', define its instability score as 'max(nums[0..i]) -
min(nums[i..n - 1])'. an index 'i' is called stable if its instability score
is less than or equal to 'k'. return the smallest stable index. if no such
index exists, return -1.
"""

from itertools import accumulate


class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        max_val = -1
        for i, j in enumerate(list(accumulate(nums[::-1], min))[::-1]):
            max_val = max(max_val, nums[i])
            if max_val - j <= k:
                return i
        return -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.firstStableIndex(nums=[5, 0, 1, 4], k=3))
    print(obj.firstStableIndex(nums=[3, 2, 1], k=1))
    print(obj.firstStableIndex(nums=[0], k=0))
