# 330. Patching Array

"""
given a sorted integer array 'nums' and an integer 'n', add/patch elements to
the array such that any number in the range '[1, n]' inclusive can be formed
by the sum of some elements in the array. return the minimum number of
patches required.
"""


class Solution(object):
    def merge(self, intervals):
        intervals.sort(key=lambda x: x[0])
        merged = []
        for i in intervals:
            if not merged or merged[-1][1] < i[0] - 1:
                merged.append(i)
            else:
                merged[-1][1] = max(merged[-1][1], i[1])
        return merged

    def minPatches(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: int
        """
        ints, patches = [[0, 0]], 0
        for i in nums:
            ints = self.merge(ints + [[j + i, k + i] for j, k in ints])
        while ints[0][1] < n:
            ints = self.merge(
                ints + [[i + ints[0][1] + 1, j + ints[0][1] + 1] for i, j in ints]
            )
            patches += 1
        return patches


if __name__ == "__main__":
    obj = Solution()
    print(obj.minPatches(nums=[1, 3], n=6))
    print(obj.minPatches(nums=[1, 5, 10], n=20))
    print(obj.minPatches(nums=[1, 2, 2], n=5))
