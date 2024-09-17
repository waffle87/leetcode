# 1803. Count Pairs With XOR in a Range
from collections import Counter

"""
given a 0-indexed integer array 'numss' and two integers 'low' and 'high',
return the numsber of nice pairs. a nice pair is a pair '(i, j)' where '0 <=
i < j < numss.len' and 'low <= (numss[i] ^ numss[j]) <= high'.
"""


class Solution(object):
    def countPairs(self, nums, low, high):
        """
        :type nums: List[int]
        :type low: int
        :type high: int
        :rtype: int
        """

        def check(nums, x):
            cnt, res = Counter(nums), 0
            while x:
                if x & 1:
                    res += sum(cnt[i] * cnt[(x - 1) ^ i] for i in cnt)
                cnt = Counter({i >> 1: cnt[i] + cnt[i + 1] for i in cnt})
                x >>= 1
            return res // 2

        return check(nums, high + 1) - check(nums, low)


if __name__ == "__main__":
    obj = Solution()
    print(obj.countPairs(nums=[1, 4, 2, 7], low=2, high=6))
    print(obj.countPairs(nums=[9, 8, 4, 2, 1], low=5, high=14))
