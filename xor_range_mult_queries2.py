# 3655. XOR After Range Multiplication Queries II
from collections import defaultdict
from math import isqrt
from typing import List

"""
you are given an integer array 'nums' of length 'n' and a 2d integer array
'queries' of size 'q', where 'queries[i] = [l, r, k, v]'. for each query, you
must apply the following operations in order. set 'idx = l', while 'idx <=
r', update 'nums[idx] = (nums[idx] * v) % (10^9 + 7)', set 'idx += k'. return
the bitwise xor of all elements in 'nums' after processing all queries.
"""


class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        magic = isqrt(n) + 1
        events = defaultdict(lambda: [1] * n)
        for l, r, k, v in queries:
            if k <= magic:
                events[k][l] = events[k][l] * v % MOD
                r2 = r + ((l - r) % k or k)
                if r2 < n:
                    events[k][r2] = events[k][r2] * pow(v, MOD - 2, MOD) % MOD
            else:
                for i in range(l, r + 1, k):
                    nums[i] = nums[i] * v % MOD
        for k, row in events.items():
            for i in range(k):
                cur = 1
                for j in range(i, n, k):
                    cur = cur * row[j] % MOD
                    nums[j] = nums[j] * cur % MOD
        ans = 0
        for x in nums:
            ans ^= x
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.xorAfterQueries(nums=[1, 1, 1], queries=[[0, 2, 1, 4]]))
    print(
        obj.xorAfterQueries(nums=[2, 3, 1, 5, 4], queries=[[1, 4, 2, 3], [0, 2, 1, 2]])
    )
