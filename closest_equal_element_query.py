# 3488. Closest Equal Element Queries
from bisect import bisect_left
from collections import defaultdict

"""
you are given a circular array 'nums' and an array 'queries'. for each query
'i', you have to find the following: the minimum distance between the element
at index 'queries[i]' and any other index 'j' in the cirrcular array where
'nums[j] == nums[queries[i]]'. if no such index exists, the answer for that
query should be -1. return an array 'ans' of the same size as 'queries' where
'answer[i]' represents the result for query 'i'.
"""


class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        n, ans = len(nums), []
        d = defaultdict(list)
        for i, j in enumerate(nums):
            d[j].append(i)
        for q in queries:
            idx = d[nums[q]]
            m = len(idx)
            if m == 1:
                ans.append(-1)
                continue
            j = bisect_left(idx, q)
            mn, mx = sorted([abs(q - idx[j - 1]), abs(q - idx[(j + 1) % m])])
            ans.append(min(mn, n - mx))
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.solveQueries(nums=[1, 3, 1, 4, 1, 3, 2], queries=[0, 3, 5]))
    print(obj.solveQueries(nums=[1, 2, 3, 4], queries=[0, 1, 2, 3]))
