# 1848. Minimum Distance to the Target Element

"""
given an integer array 'nums' and two integers 'target' and 'start', find an
index 'i' such that 'nums[i] == target' and 'abs(i - start)' is minimised.
note that 'abs(x)' is the absolute value of 'x'. return 'abs(i - start)'. it
is guaranteed that 'target' exists in 'nums'.
"""


class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        return min(abs(i - start) for i, j in enumerate(nums) if j == target)


if __name__ == "__main__":
    obj = Solution()
    print(obj.getMinDistance(nums=[1, 2, 3, 4, 5], target=5, start=3))
    print(obj.getMinDistance(nums=[1], target=1, start=0))
    print(obj.getMinDistance(nums=[1, 1, 1, 1, 1, 1, 1, 1, 1, 1], target=1, start=0))
