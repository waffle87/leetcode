# 3761. Minimum Absolute Distance Between Mirror Pairs

"""
you are given an integer array 'nums'. a mirror pair is a pair of indices
'(i, j)' such that '0 <= i < j < nums.length' and 'reverse(nums[i]) ==
nums[j]'. return the minimum absolute distance between the indices of any
mirror pair. the absolute distance between indices is 'i' and 'j' is 'abs(i -
j)'. if no mirror pairs exists, return -1.
"""


class Solution:
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        ans = 100000
        vis = {}
        for i, j in enumerate(nums):
            if j in vis:
                ans = min(ans, i - vis[j])
            vis[int(str(j)[::-1])] = i
        return -(ans == 100000) | ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minMirrorPairDistance(nums=[12, 21, 45, 33, 54]))
    print(obj.minMirrorPairDistance(nums=[120, 21]))
    print(obj.minMirrorPairDistance(nums=[21, 120]))
