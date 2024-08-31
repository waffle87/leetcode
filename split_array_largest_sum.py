# 410. Split Array Largest Sum
from collections import defaultdict

"""
given an integer array 'nums' and an integer 'k' split 'nums' into 'k' non
empty subarrays such that the largest sum of any subarray is minimised.
return the minimised largest sum of the split. a subarray is a contiguous
part of the array
"""


class Solution(object):
    def helper(self, i, nums, k, cache, cnt):
        if i == len(nums):
            return 0
        elif k == 1:
            return sum(nums[i:])
        else:
            if i in cache and k in cache[i]:
                return cache[i][k]
            cache[i][k] = float("inf")
            for j in range(1, len(nums) + 1):
                left, right = (
                    cnt[i + j] - cnt[i],
                    self.helper(i + j, nums, k - 1, cache, cnt),
                )
                cache[i][k] = min(cache[i][k], max(left, right))
                if left > right:
                    break
            return cache[i][k]

    def splitArray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        cnt = [0]
        for i in nums:
            cnt.append(cnt[-1] + i)
        cache = defaultdict(dict)
        return self.helper(0, nums, k, cache, cnt)


if __name__ == "__main__":
    obj = Solution()
    print(obj.splitArray(nums=[7, 2, 5, 10, 8], k=2))
    print(obj.splitArray(nums=[1, 2, 3, 4, 5], k=2))
