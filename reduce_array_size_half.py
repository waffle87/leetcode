# 1338. Reduce Array Size to The Half
from collections import Counter

"""
you are given an integer array 'arr'. you can choose a set of integers and
remove all the occurences of these integers in the array. return the minimum
size of the set so that at least half of the integers in the array are
removed.
"""


class Solution(object):
    def minSetSize(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        cnt = Counter(arr)
        freq = list(cnt.values())
        freq.sort()
        ans, removed, half = 0, 0, len(arr) // 2
        while removed < half:
            ans += 1
            removed += freq.pop()
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minSetSize(arr=[3, 3, 3, 3, 5, 5, 5, 2, 2, 7]))
    print(obj.minSetSize(arr=[7, 7, 7, 7, 7, 7]))
