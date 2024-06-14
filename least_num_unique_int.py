# 1481. Least Number of Unique Integers after K Removals
from collections import Counter

"""
given an array of integers 'arr' and an integer 'k', find the least number of
unique integers after removing exactly 'k' elements.
"""


class Solution(object):
    def findLeastNumOfUniqueInts(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: int
        """
        mp = collections.Counter(arr)
        v = list(mp.values())
        cnt = 0
        v.sort()
        for i in range(len(v)):
            if k > v[i]:
                k -= v[i]
                v[i] = 0
            else:
                v[i] -= k
                k = 0
            if v[i] != 0:
                cnt += 1
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.findLeastNumOfUniqueInts(arr=[5, 5, 4], k=1))
    print(obj.findLeastNumOfUniqueInts(arr=[4, 3, 1, 1, 3, 3, 2], k=3))
