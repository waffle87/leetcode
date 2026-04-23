# 2615. Sum of Distances
from collections import defaultdict

"""
you are given a 0 indexed integer array 'nums'. there exists an array 'arr'
of length 'nums.length' where 'arr[i]' is the sum of '|i - j|' over all 'j'
such that 'nums[j] == nums[i]' and 'j != i'. if there is no such 'j', set
'arr[i]' to be 0. return the array 'arr'.
"""


class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        n = len(nums)
        groups = defaultdict(list)
        for i, v in enumerate(nums):
            groups[v].append(i)
        ans = [0] * n
        for group in groups.values():
            total = sum(group)
            prefix_total = 0
            m = len(group)
            for i, idx in enumerate(group):
                ans[idx] = total - prefix_total * 2 + idx * (2 * i - m)
                prefix_total += idx
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.distance(nums=[1, 3, 1, 1, 2]))
    print(obj.distance(nums=[0, 5, 3]))
