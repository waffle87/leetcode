# 3347. Maximum Frequency of an Element After Performing Operations II
import bisect
from collections import defaultdict

"""
you are given an integer array 'nums' and two integers 'k' and
'numOperations'. you must perform an operation 'numOperations' times on
'nums', where in each operation you select an index 'i' that was not selected
in any previous operations, and add an integer in the range '[-k, k]' to
'nums[i]'. return the maximum possible frequency of any elements in 'nums'
after performing the operations.
"""


class Solution(object):
    def maxFrequency(self, nums, k, numOperations):
        """
        :type nums: List[int]
        :type k: int
        :type numOperations: int
        :rtype: int
        """
        nums.sort()
        ans, modes = 0, set()
        num_cnt = defaultdict(int)

        def add_mode(value):
            modes.add(value)
            if value - k >= nums[0]:
                modes.add(value - k)
            if value + k <= nums[-1]:
                modes.add(value + k)

        prev = 0
        for i in range(len(nums)):
            if nums[i] != nums[prev]:
                num_cnt[nums[prev]] = i - prev
                ans = max(ans, i - prev)
                add_mode(nums[prev])
                prev = i
        num_cnt[nums[prev]] = len(nums) - prev
        ans = max(ans, len(nums) - prev)
        add_mode(nums[prev])
        for mode in sorted(modes):
            l = bisect.bisect_left(nums, mode - k)
            r = bisect.bisect_right(nums, mode + k) - 1
            if mode in num_cnt:
                tmp = min(r - l + 1, num_cnt[mode] + numOperations)
            else:
                tmp = min(r - l + 1, numOperations)
            ans = max(ans, tmp)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxFrequency(nums=[1, 4, 5], k=1, numOperations=2))
    print(obj.maxFrequency(nums=[5, 11, 20, 20], k=5, numOperations=1))
