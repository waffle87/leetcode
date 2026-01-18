# 1655. Distribute Repeating Integers
import collections
from functools import lru_cache

"""
you are given an array of 'n' integers, 'nums' where there are at most 50
unique values in the array. you are also given an array of 'm' customer order
quantities 'quantity', where 'quantity[i]' is the amount of integers the i'th
customer ordered. determine if it is possible to distribute 'nums' such that
the i'th customer gets exactly 'quantity[i]' integers, the integers the i'th
customer gets are all equal, and every customer is satisfied. return 'true'
if it is possible to distribute 'nums' according to the above conditions.
"""


class Solution(object):
    def canDistribute(self, nums, quantity):
        """
        :type nums: List[int]
        :type quantity: List[int]
        :rtype: bool
        """
        c = collections.Counter()
        a = sorted(c.values())
        n, m = len(a), len(quantity)
        all = (1 << m) - 1
        mask_sum = collections.defaultdict(int)
        for i in range(1 << m):
            for j in range(m):
                if (1 << j) & i:
                    mask_sum[i] += quantity[j]

        @lru_cache(None)
        def dfs(i, mask):
            if mask == 0:
                return True
            if i == n:
                return False
            submask = mask
            while submask:
                if mask_sum[submask] <= a[i] and dfs(i + 1, mask ^ submask):
                    return True
                submask = (submask - 1) & mask
            return dfs(i + 1, mask)

        return dfs(0, all)


if __name__ == "__main__":
    obj = Solution()
    print(obj.canDistribute(nums=[1, 2, 3, 4], quantity=[2]))
    print(obj.canDistribute(nums=[1, 2, 3, 3], quantity=[2]))
    print(obj.canDistribute(nums=[1, 1, 2, 2], quantity=[2, 2]))
