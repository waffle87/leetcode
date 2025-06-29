# 1498. Number of Subsequences That Satisfy the Given Sum Condition

"""
given an array of integers 'nums' and an integer 'target'
return the numbe of non-empty subsequences of 'nums' such
that the sum of the minimum and maximum element on it is
less or equal to 'target'. return modulo 10^9+7
"""


class Solution(object):
    def numSubseq(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        pows, mod = [1], 10**9 + 7
        nums.sort()
        for i in range(1, len(nums)):
            pows.append((pows[-1] << 1) % mod)
        ans, l, r = 0, 0, len(nums) - 1
        while l <= r:
            if nums[l] + nums[r] > target:
                r -= 1
                continue
            ans = (ans + pows[r - l]) % mod
            l += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.numSubseq(nums=[3, 5, 6, 7], target=9))
    print(obj.numSubseq(nums=[3, 3, 6, 8], target=10))
    print(obj.numSubseq(nums=[2, 3, 3, 4, 6, 7], target=12))
