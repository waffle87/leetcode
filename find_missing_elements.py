# 3731. Find Missing Elements
from typing import List

"""
you are given an integer array 'nums' consisting of unique integers.
originally, 'nums' contained every integer within a certain range. however,
some integers might have gone missing from the array. the smallest and
largest integers of the original range are still present in 'nums'. return a
sorted list of all the missing integers in this range. if no integers are
missing, return an empty list.
"""


class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        mn, mx = min(nums), max(nums)
        vis, ans = set(nums), []
        for i in range(mn, mx + 1):
            if i not in vis:
                ans.append(i)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.findMissingElements(nums=[1, 4, 2, 5]))
    print(obj.findMissingElements(nums=[7, 8, 6, 9]))
    print(obj.findMissingElements(nums=[5, 1]))
