# 974. Subarray Sums Divisible by K

"""
given an integer array 'nums' and an integer 'k', return the number of non
empty subarrays that have a sum divisible by 'k'. a subarray is contiguous
part of an array.
"""


class Solution(object):
    def subarraysDivByK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        ans, prefix = 0, 0
        cnt = [1] + [0] * k
        for i in nums:
            prefix = (prefix + i) % k
            ans += cnt[prefix]
            cnt[prefix] += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.subarraysDivByK(nums=[4, 5, 0, -2, -3, 1], k=5))
    print(obj.subarraysDivByK(nums=[5], k=9))
