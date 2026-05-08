# 3629. Minimum Jumps to Reach End via Prime Teleportation
from collections import defaultdict
from typing import List

"""
you are given an integer array 'nums' of length 'n'. you start at index 0,
and your goal is to reach index 'n - 1'. from any index 'i', you may perform
onee of the following operations: adjacent step: jump to index 'i + 1' or 'i
- 1', if the index is within bounds, or prime teleportation: if 'nums[i]' is
a prime number, you may instantly jump to any index 'j != i' such that
'nums[j] % p == 0'. return the minimum number of jumps to reach the index 'n
- 1'.
"""

MX = 1_000_001
factors = [[] for _ in range(MX)]
for i in range(2, MX):
    if not factors[i]:
        for j in range(i, MX, i):
            factors[j].append(i)


class Solution:
    def minJumps(self, nums: List[int]) -> int:
        n = len(nums)
        edges = defaultdict(list)
        for i, a in enumerate(nums):
            for p in factors[a]:
                edges[p].append(i)
        ans = 0
        vis = [False] * n
        vis[0] = True
        q = [0]
        while True:
            q2 = []
            for i in q:
                if i == n - 1:
                    return ans
                if i > 0 and not vis[i - 1]:
                    vis[i - 1] = True
                    q2.append(i - 1)
                if i < n - 1 and not vis[i + 1]:
                    vis[i + 1] = True
                    q2.append(i + 1)
                if len(factors[nums[i]]) == 1:
                    p = nums[i]
                    for j in edges[p]:
                        if not vis[j]:
                            vis[j] = True
                            q2.append(j)
                    edges[p].clear()
            q = q2
            ans += 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.minJumps(nums=[1, 2, 4, 6]))
    print(obj.minJumps(nums=[2, 3, 4, 7, 9]))
    print(obj.minJumps(nums=[4, 6, 5, 8]))
