# 1460. Make Two Arrays Equal by Reversing Subarrays
from collections import Counter

"""
you are given two integer arrays of equal length 'target' and 'arr'. in one
step, you can select any non empty subarray of 'arr' and reverse it. you are
allowed to make any number of steps. return true if you can make 'arr' equal
to 'target' or false otherwise.
"""


class Solution(object):
    def canBeEqual(self, target, arr):
        """
        :type target: List[int]
        :type arr: List[int]
        :rtype: bool
        """
        if len(target) != len(arr):
            return False
        cnt = Counter(target)
        for num in arr:
            cnt[num] -= 1
        return all(cnt[num] == 0 for num in cnt)


if __name__ == "__main__":
    obj = Solution()
    print(obj.canBeEqual(target=[1, 2, 3, 4], arr=[2, 4, 1, 3]))
    print(obj.canBeEqual(target=[7], arr=[7]))
    print(obj.canBeEqual(target=[3, 7, 9], arr=[3, 7, 11]))
