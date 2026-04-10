# 3740. Minimum Distance Between Three Equal Elements I
from typing import List

"""
you are given an integer array 'nums'. a tuple '(i, j, k)' of 3 distinct
indices is good if 'nums[i] == nums[j] == nums[k]'. the distance of a good
tuple is 'abs(i - j) + abs(j - k) + abs(k - k)', where 'abs(x)' denotes the
absolute value of 'x'. return an integer denoting the minimum possible
distance of a good tuple. if no good tuples exist, return -1.
"""


class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        n = len(nums)
        prev = [0] * n
        res = 300
        for i in range(n):
            val, pos = nums[i] - 1, i + 1
            pack = prev[val]
            old, cur = pack & 255, pack >> 8
            prev[val] = cur | (pos << 8)
            if old:
                res = min(res, (pos - old) << 1)
        return -(res == 300) | res


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumDistance(nums=[1, 2, 1, 1, 3]))
    print(obj.minimumDistance(nums=[1, 1, 2, 3, 2, 1, 2]))
    print(obj.minimumDistance(nums=[1]))
