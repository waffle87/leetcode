# 2770. Maximum Number of Jumps to Reach the Last Index
from typing import List

"""
you are given an 0-indexed array 'nums' of 'n' integers and an integer
'target'. you are initially positioned at index '0'. in one step, you can
jump from index 'i' to index 'j' such that '0 <= i < j < n' and '-target <=
nums[j] - nums[i] <= target'. return the maximum number of jumps you can make
to reach each index 'n - 1'. if there is no way to reach index 'n - 1',
return -1.
"""


class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        def dfs(i: int):
            if i == len(nums) - 1:
                return 0

            res = float("-inf")
            for j in range(i + 1, len(nums)):
                if abs(nums[i] - nums[j]) <= target:
                    res = max(res, dfs(j) + 1)
            return res

        ans = dfs(0)
        return -1 if ans < 0 else ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumJumps(nums=[1, 3, 6, 4, 1, 2], target=2))
    print(obj.maximumJumps(nums=[1, 3, 6, 4, 1, 2], target=3))
    print(obj.maximumJumps(nums=[1, 3, 6, 4, 1, 2], target=0))
