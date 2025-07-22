# 1695. Maximum Erasure Value

"""
you are given an array of posiive integers 'nums' and want to erase a
subarray containing unique elements. the score you get by erasing the
subarray is equal to the sum of its elements. return the maximum score you
can get by erasing exactly one subarray. an array 'b' is called to be a
subarray of 'a' if it forms a contiguous subsequence of 'a' that is if it is
equal to 'a[l], a[l + 1], ..., a[r]' for some '(l, r)'
"""


class Solution(object):
    def maximumUniqueSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        beg, end, ans = 0, 0, 0
        s, n, m = set(), len(nums), 0
        while end < n:
            if nums[end] not in s:
                m += nums[end]
                s.add(nums[end])
                end += 1
                ans = max(ans, m)
            else:
                m -= nums[beg]
                s.remove(nums[beg])
                beg += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumUniqueSubarray(nums=[4, 2, 4, 5, 6]))
    print(obj.maximumUniqueSubarray(nums=[5, 2, 1, 2, 5, 2, 1, 2, 5]))
