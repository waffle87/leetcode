# 2176. Count Equal and Divisible Pairs in an Array
import collections
from math import gcd

"""
given a 0-indexed integer array 'nums' of length 'n' and an integer 'k',
return the number of pairs '(i, j)' where '0 <= i < j < n' such that 'nums[i]
== nums[j]' and '(i * j)' is divisble by 'k'.
"""


class Solution(object):
    def countPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        ids = collections.defaultdict(list)
        for i, j in enumerate(nums):
            ids[j].append(i)
        ans = 0
        for i in ids.values():
            gcds = collections.Counter()
            for j in i:
                curr_i = gcd(j, k)
                ans += sum(
                    cnt for curr_j, cnt in gcds.items() if curr_i * curr_j % k == 0
                )
                gcds[curr_i] += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countPairs(nums=[3, 1, 2, 2, 2, 1, 3], k=2))
    print(obj.countPairs(nums=[1, 2, 3, 4], k=1))
