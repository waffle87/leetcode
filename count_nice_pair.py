# 1814. Count Nice Pairs in an Array
import collections

"""
given an array 'nums' that consists of non-negative integers. let us define
'rev(x)' as the reverse of the non-negative integer 'x'. for example,
'rev(123) = 321' and 'rev(120) = 21'. a pair of indices '(i, j)' is nice if
it satisfies all of the following conditions: '0 <= i < j < nums.length' and
'nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])'. return the number of nice
pairs of indices. since that number be very large, return it modulo 1e9+7
"""


class Solution(object):
    def countNicePairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0
        cnt = collections.Counter()
        for i in nums:
            b = int(str(i)[::-1])
            ans += cnt[i - b]
            cnt[i - b] += 1
        return ans % (10**9 + 7)


if __name__ == "__main__":
    obj = Solution()
    print(obj.countNicePairs([42, 11, 1, 97]))  # expect: 2
    print(obj.countNicePairs([13, 10, 35, 24, 76]))  # expect: 4
