# 560. Subarray Sum Equals K

"""
given an array of integers 'nums' and an integer 'k', return the total number
of subarrays whose sum equals to 'k'. a subarray is a contiguous non-empty
sequence of elements within an array.
"""


class Solution(object):
    def subarraySum(self, nums, k):
        ans = 0
        prefix_sum = 0
        d = {0: 1}
        for n in nums:
            prefix_sum += n
            if prefix_sum - k in d:
                ans += d[prefix_sum - k]
            if prefix_sum not in d:
                d[prefix_sum] = 1
            else:
                d[prefix_sum] += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.subarraySum([1, 1, 1], 2))  # expect: 2
    print(obj.subarraySum([1, 2, 3], 3))  # expect: 2
